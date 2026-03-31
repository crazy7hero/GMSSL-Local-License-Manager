#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "licensegenerator.h"
#include "licensevalidator.h"
#include "configmanager.h"
#include "logmanager.h"
#include "gmsslcrypto.h"
#include "keyconfigdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStyleFactory>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QTabWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QListWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QTimer>
#include <QRandomGenerator>
#include <QApplication>
#include <QFileInfo>
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupUI();


    // 设置日志文本框的文本交互格式(启用富文本（Rich Text）支持,HTML格式的文本，可以显示不同颜色、字体、大小、加粗、斜体等格式化文本)
    ui->logTextEdit->setAcceptRichText(true);
    // 设置日志框为只读但可选
    // 1. 用鼠标选择日志内容进行复制
    // 2. 用键盘选择文本
    // 3. 但不能编辑修改日志内容
    ui->logTextEdit->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

    // 初始化日志系统
    if (!LogManager::instance().initialize(NULL, ui->logTextEdit)) {
        QMessageBox::warning(this, "警告", "日志系统初始化失败");
    }

    loadConfig();


    LOG_INFO("SYSTEM", "国密授权管理系统启动");
    LOG_INFO("SYSTEM", QString("版本: %1").arg(QApplication::applicationVersion()));
    //LOG_INFO("SYSTEM", QString("Qt版本: %1").arg(QT_VERSION_STR));
    //LOG_INFO("SYSTEM", QString("编译器: %1").arg(QT_VERSION_STR));

    // 显示配置信息
    LOG_INFO("CONFIG", "配置加载完成");
    LOG_INFO("CONFIG", QString("私钥路径: %1").arg(ConfigManager::instance().getPrivateKeyPath()));
    LOG_INFO("CONFIG", QString("公钥路径: %1").arg(ConfigManager::instance().getPublicKeyPath()));
    //LOG_INFO("CONFIG", QString("日志文件: %1").arg(logFile));

    // 生成默认授权ID
    //onGenerateLicenseIdClicked();
}

MainWindow::~MainWindow()
{
    LOG_INFO("SYSTEM", "应用程序退出");
    delete ui;
}

void MainWindow::setupUI()
{
    // 设置窗口标题
    setWindowTitle("国密授权管理系统");

    // 设置窗口大小
    resize(800, 500);

    QAction *exitAction = new QAction("退出", this);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    QAction * configAction = new QAction("配置信息", this);
    connect(configAction, &QAction::triggered, this, &MainWindow::showConfigDialog);


    QAction *aboutAction = new QAction("关于", this);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);

    QAction *reloadconfig = new QAction("配置密钥", this);
    connect(reloadconfig, &QAction::triggered, this, &MainWindow::showKeyConfigDialog);


    // 创建工具栏
    QToolBar *toolBar = addToolBar("主工具栏");
    toolBar->addAction(configAction);
    toolBar->addSeparator();
    toolBar->addAction(reloadconfig);
    toolBar->addSeparator();
    toolBar->addAction(exitAction);
    toolBar->addSeparator();
    toolBar->addAction(aboutAction);

    toolBar->setMovable(false);
    toolBar->setFloatable(false);


    // 设置日志文本编辑框
    ui->logTextEdit->setReadOnly(true);
    ui->logTextEdit->setFont(QFont("Consolas", 9));

    // 连接信号槽
    // 密钥管理页
    connect(ui->generateKeysButton, &QPushButton::clicked, this, &MainWindow::onGenerateKeysClicked);
    connect(ui->browseKeyDirButton, &QPushButton::clicked, this, &MainWindow::onBrowseKeyDirClicked);

    // 授权生成页
    connect(ui->createLicenseButton, &QPushButton::clicked, this, &MainWindow::onCreateLicenseClicked);
    connect(ui->browseLicenseOutputButton, &QPushButton::clicked, this, &MainWindow::onBrowseLicenseOutputClicked);

    // 授权验证页
    connect(ui->verifyLicenseButton, &QPushButton::clicked, this, &MainWindow::onVerifyLicenseClicked);
    connect(ui->browseLicenseFileButton, &QPushButton::clicked, this, &MainWindow::onBrowseLicenseFileClicked);

    // 日志页
    connect(ui->clearLogButton, &QPushButton::clicked, this, &MainWindow::onClearLogClicked);
    connect(ui->exportLogButton, &QPushButton::clicked, this, &MainWindow::onExportLogClicked);
    connect(ui->logLevelCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onLogLevelChanged);

    // 设置默认值
    ui->issueDateEdit->setDateTime(QDateTime::currentDateTime());
    ui->expireDateEdit->setDateTime(QDateTime::currentDateTime().addDays(365));


    // 设置日志级别选择框

    ui->logLevelCombo->addItem("INFO", LogManager::LEVEL_INFO);
    ui->logLevelCombo->addItem("WARNING", LogManager::LEVEL_WARNING);
    ui->logLevelCombo->addItem("ERROR", LogManager::LEVEL_ERROR);

#ifdef DEBUG
    ui->logLevelCombo->addItem("DEBUG", LogManager::LEVEL_DEBUG);
    // 使用findData查找DEBUG级别的索引
    int debugIndex = ui->logLevelCombo->findData(LogManager::LEVEL_DEBUG);
    if (debugIndex != -1) {
        ui->logLevelCombo->setCurrentIndex(debugIndex);
    }
#else
    // 查找INFO级别的索引
    int infoIndex = ui->logLevelCombo->findData(LogManager::LEVEL_INFO);
    if (infoIndex != -1) {
        ui->logLevelCombo->setCurrentIndex(infoIndex);
    }
#endif

#ifdef DEBUG
    QString versiontemp = "1.0";
    ui->versionEdit->setText(versiontemp);
    QString mactemp = "00-11-22-33-44-55";
    ui->macAddressEdit->setText(mactemp);
    ui->validateMacEdit->setText(mactemp);
#endif

    ui->keyPasswordEdit->setEchoMode(QLineEdit::Password);  // 默认密码模式
    ui->keyPasswordEdit->setPlaceholderText("输入SM2密钥密码（至少8位）");


    if(ui->showPasswordCheck){
        ui->showPasswordCheck->setChecked(false);
        ui->showPasswordCheck->setToolTip("勾选以显示明文密码");
    }
   // connect(ui->showPasswordCheck, &QCheckBox, this, &MainWindow

    //密码显示
    if (ui->showPasswordCheck) {
        // 修复警告：使用 stateChanged
        connect(ui->showPasswordCheck, &QCheckBox::stateChanged,
                this, [this](int state) {
                    bool isChecked = (state == Qt::Checked);
                    ui->keyPasswordEdit->setEchoMode(
                        isChecked ? QLineEdit::Normal : QLineEdit::Password
                        );
                });
    }
    // 定时更新状态栏
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateStatusBar);
    timer->start(1000);
}

void MainWindow::loadConfig()
{
    LOG_INFO("SYSTEM", "正在加载配置...");

    // 从配置管理器加载路径
    ConfigManager &config = ConfigManager::instance();

    //ui->keyPasswordEdit->setText(config.getSm2KeyPassword());
    config.loadConfig();
    LOG_INFO("CONFIG", "配置加载完成");
}

bool MainWindow::checkKeysExist(const QString &dirPath)
{
    QDir dir(dirPath);

    // 常见的密钥文件名列表
    QStringList keyFiles = {
        "sm4_key.bin",
        "sm2_private.pem",
        "sm2_public.pem"
    };

    QStringList foundFiles;

    for (const QString &fileName : keyFiles) {
        if (QFile::exists(dir.absoluteFilePath(fileName))) {
            foundFiles.append(fileName);
        }
    }

    if (!foundFiles.isEmpty()) {
        LOG_WARNING("KEYGEN", QString("发现已存在的密钥文件: %1").arg(foundFiles.join(", ")));
        return true;
    }

    return false;
}

bool MainWindow::confirmOverwrite(const QString &dirPath)
{
    QDir dir(dirPath);
    QStringList foundFiles;

    // 精确匹配特定的密钥文件名
    QStringList exactFileNames = {
                                  "sm4_key.bin", "sm2_private.pem", "sm2_public.pem",
                                  "key_config.ini"};

    // 先检查确切的文件名
    for (const QString &fileName : exactFileNames) {
        if (QFile::exists(dir.absoluteFilePath(fileName))) {
            QFileInfo fileInfo(dir.absoluteFilePath(fileName));
            foundFiles.append(QString("%1 (%2 字节)").arg(fileName).arg(fileInfo.size()));
        }
    }

    if (foundFiles.isEmpty()) {
        // 如果没有精确匹配，再检查通配符
        QStringList patterns = {"*key*.pem", "*key*.bin", "*config*.ini"};
        for (const QString &pattern : patterns) {
            QStringList files = dir.entryList(QStringList() << pattern, QDir::Files);
            for (const QString &file : files) {
                // 检查是否已添加（防止重复）
                bool alreadyAdded = false;
                for (const QString &existing : foundFiles) {
                    if (existing.startsWith(file + " (")) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    QFileInfo fileInfo(dir.absoluteFilePath(file));
                    foundFiles.append(QString("%1 (%2 字节)").arg(file).arg(fileInfo.size()));
                }
            }
        }
    }

    if (foundFiles.isEmpty()) {
        return true;
    }

    // 构建消息
    QString message = QString("目录 %1 中已存在以下密钥文件:\n\n")
                          .arg(QDir::toNativeSeparators(dirPath));

    // 只显示前5个文件，避免对话框太长
    int maxDisplay = 5;
    for (int i = 0; i < qMin(foundFiles.size(), maxDisplay); i++) {
        message += QString("• %1\n").arg(foundFiles[i]);
    }

    if (foundFiles.size() > maxDisplay) {
        message += QString("... 还有 %1 个文件\n").arg(foundFiles.size() - maxDisplay);
    }

    message += "\n继续生成将会覆盖这些文件。\n是否要继续？";

    // 显示确认对话框
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("确认覆盖");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("检测到已存在的密钥文件");
    msgBox.setInformativeText(message);


    // 设置按钮
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    // 设置按钮文本
    msgBox.button(QMessageBox::Yes)->setText("继续生成");
    msgBox.button(QMessageBox::No)->setText("取消");

    int result = msgBox.exec();

    if (result == QMessageBox::Yes) {
        LOG_INFO("KEYGEN", "用户选择覆盖现有密钥文件");
        return true;
    } else {
        LOG_INFO("KEYGEN", "用户取消了密钥生成");
        return false;
    }
}

void MainWindow::onGenerateKeysClicked()
{
    QString password = ui->keyPasswordEdit->text();
    if (password.length() < 8) {
        LOG_WARNING("KEYGEN", "密码长度至少8位");
        QMessageBox::warning(this, "警告", "密码长度至少8位");
        return;
    }

    QString keyDir = ui->keyDirEdit->text();
    if (keyDir.isEmpty()) {
        LOG_WARNING("KEYGEN", "请选择密钥目录");
        QMessageBox::warning(this, "警告", "请选择密钥目录");
        return;
    }

    if (checkKeysExist(keyDir)) {
        // 如果存在，询问用户是否继续
        if (!confirmOverwrite(keyDir)) {
            // 用户选择取消
            ui->statusbar->showMessage("密钥生成已取消", 3000);
            return;
        }
    }

    LOG_INFO("KEYGEN", "开始生成密钥...");
    ui->keyProgressBar->setVisible(true);
    ui->keyProgressBar->setRange(0, 0); // 不确定进度

    ui->generateKeysButton->setEnabled(false);
    ui->statusbar->showMessage("正在生成密钥...");

    // 使用QTimer延迟执行，避免阻塞UI
    QTimer::singleShot(100, this, [this, password, keyDir]() {
        LicenseGenerator generator;
        bool success = generator.generateKeys(password, keyDir);
        ui->keyProgressBar->setVisible(false);
        ui->generateKeysButton->setEnabled(true);

        if (success) {
            LOG_INFO("KEYGEN", "密钥生成成功");

            // 提示用户是否加载新生成的密钥
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "密钥生成成功",
                                          "密钥文件已生成！\n\n"
                                          "私钥文件: sm2_private.pem\n"
                                          "公钥文件: sm2_public.pem\n"
                                          "SM4密钥: sm4_key.bin\n\n"
                                          "是否加载这些新生成的密钥文件？",
                                          QMessageBox::Yes | QMessageBox::No,
                                          QMessageBox::Yes);

            if (reply == QMessageBox::Yes) {
                // 用户选择加载新生成的密钥
                ConfigManager &config = ConfigManager::instance();
                config.setPrivateKeyPath(keyDir + "/sm2_private.pem");
                config.setPublicKeyPath(keyDir + "/sm2_public.pem");
                config.setSm4KeyPath(keyDir + "/sm4_key.bin");
                config.setSm2KeyPassword(password);

                // 尝试加载密钥以验证
                bool keysLoaded = config.loadConfig();

                if (keysLoaded && config.saveConfig()) {
                    LOG_INFO("CONFIG", "新密钥已加载并保存到配置");


                    QMessageBox::information(this, "成功",
                                             "新生成的密钥已成功加载并保存到配置文件中！");
                } else {
                    QMessageBox::warning(this, "警告",
                                         "密钥文件生成成功，但加载验证失败。\n"
                                         "请手动检查密钥文件是否正确。");
                }

            } else if (reply == QMessageBox::No) {
                // 用户选择不加载，只显示成功消息
                QMessageBox::information(this, "密钥生成完成",
                                         "密钥文件已生成，但未加载到当前配置。\n\n"
                                         "您可以在需要时通过工具栏[配置密钥]加载这些密钥文件。");
            }
        } else {
            LOG_ERROR("KEYGEN", QString("密钥生成失败: %1").arg(generator.getLastError()));
            QMessageBox::critical(this, "失败",
                                  QString("密钥生成失败:\n%1").arg(generator.getLastError()));
            ui->statusbar->showMessage("密钥生成失败", 3000);
        }
    });
}

void MainWindow::onBrowseKeyDirClicked()
{
    QString defaultDir = QCoreApplication::applicationDirPath() + "/keys";
    QString dirPath = QFileDialog::getExistingDirectory(
        this,
        "选择密钥保存目录",
        defaultDir,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );

    if (!dirPath.isEmpty()) {
        ui->keyDirEdit->setText(dirPath);
        LOG_INFO("UI",  (QString("选择密钥保存目录: %1").arg(dirPath)));
    }
}

void MainWindow::onCreateLicenseClicked()
{
    LOG_INFO("LICENSE", "开始生成授权文件...");

    // ================ 1. 验证版本号 ================
    QString version = ui->versionEdit->text().trimmed();
    if (version.isEmpty()) {
        showMessage("版本号不能为空", true);
        LOG_ERROR("LICENSE", "版本号为空");
        return;
    }

    // ================ 2. 验证MAC地址 ================
    QString macAddress = ui->macAddressEdit->text().trimmed();
    if (macAddress.isEmpty()) {
        showMessage("MAC地址不能为空", true);
        LOG_ERROR("LICENSE", "MAC地址为空");
        return;
    }

    // 验证MAC地址格式
    QString normalizedMac = normalizeMacAddress(macAddress);
    if (normalizedMac.isEmpty()) {
        showMessage("MAC地址格式不正确，请使用以下格式：\n"
                    "00:11:22:33:44:55 或 00-11-22-33-44-55", true);
        LOG_ERROR("LICENSE", QString("MAC地址格式错误: %1").arg(macAddress));
        return;
    }

    // ================ 3. 验证有效期 ================
    QDateTime issueDate = ui->issueDateEdit->dateTime();
    QDateTime expireDate = ui->expireDateEdit->dateTime();

    if (issueDate.isNull() || !issueDate.isValid()) {
        showMessage("签发日期无效", true);
        LOG_ERROR("LICENSE", "签发日期无效");
        return;
    }

    if (expireDate.isNull() || !expireDate.isValid()) {
        showMessage("过期日期无效", true);
        LOG_ERROR("LICENSE", "过期日期无效");
        return;
    }

    if (expireDate <= issueDate) {
        showMessage("过期日期必须晚于签发日期", true);
        LOG_ERROR("LICENSE", "过期日期早于签发日期");
        return;
    }

    // ================ 4. 验证输出路径 ================
    QString outputPath = ui->outputPathEdit->text();
    if (outputPath.isEmpty()) {
        showMessage("请选择输出路径", true);
        LOG_ERROR("LICENSE", "输出路径为空");
        return;
    }

    // ================ 5. 验证密钥文件 ================
    ConfigManager &config = ConfigManager::instance();
    config.loadConfig();//每次生成都加载最新的配置密钥
    QString privateKeyPath = config.getPrivateKeyPath();
    QString sm4KeyPath = config.getSm4KeyPath();
    QString password = config.getSm2KeyPassword();

    // 验证私钥文件
    if (privateKeyPath.isEmpty() || !QFile::exists(privateKeyPath)) {
        showMessage("私钥文件不存在，请重新配置密钥路径或者重新生成密钥", true);
        LOG_ERROR("LICENSE", QString("私钥文件不存在: %1").arg(privateKeyPath));
        return;
    }

    // 验证SM4密钥文件
    if (sm4KeyPath.isEmpty() || !QFile::exists(sm4KeyPath)) {
        showMessage("SM4密钥文件不存在，请重新配置密钥路径或者重新生成密钥", true);
        LOG_ERROR("LICENSE", QString("SM4密钥文件不存在: %1").arg(sm4KeyPath));
        return;
    }

    // ================ 6. 加载配置中的SM4密钥 ================
    GmSSLCrypto &crypto = GmSSLCrypto::instance();
    QByteArray sm4Key;
    if (!crypto.loadSm4Key(sm4KeyPath, sm4Key)) {
        showMessage("SM4密钥加载失败，请检查密钥文件", true);
        LOG_ERROR("LICENSE", "SM4密钥加载失败");
        return;
    }

    if (sm4Key.size() != 16) {
        showMessage("SM4密钥长度不正确（应为16字节）", true);
        LOG_ERROR("LICENSE", QString("SM4密钥长度错误: %1 字节").arg(sm4Key.size()));
        return;
    }

    LOG_INFO("LICENSE", QString("SM4密钥加载成功，长度: %1 字节").arg(sm4Key.size()));

    // ================ 7. 构建授权信息 ================
    LicenseGenerator::LicenseInfo licenseInfo;
    licenseInfo.version = version;
    licenseInfo.issueDate = issueDate;
    licenseInfo.expireDate = expireDate;
    licenseInfo.macAddress = normalizedMac;


    // ================ 8. 生成授权文件名 ================
   // QString fileName = QString("%1/license_%2.lic")
                           //.arg(outputPath)
                           //.arg(QDateTime::currentDateTime().toString("yyyyMMddHHmmss"));

    // 禁用生成按钮，显示进度
    ui->createLicenseButton->setEnabled(false);
    ui->statusbar->showMessage("正在生成授权文件...");
    ui->keyProgressBar->setVisible(true);
    ui->keyProgressBar->setRange(0, 0); // 不确定进度

    // 使用延迟执行避免阻塞UI
    QTimer::singleShot(100, this, [=]() {
        LicenseGenerator generator;

        // 使用新的哈希+签名+加密方式生成授权文件
        bool success = generator.generateLicenseWithHashAndSign(licenseInfo,
                                                                privateKeyPath,
                                                                password,
                                                                sm4Key,
                                                                outputPath);

        if (success) {
            // 成功时显示成功弹窗
            QString successMessage = QString("授权文件生成成功！\n\n"
                                             "文件: %1\n"
                                             "版本: %2\n"
                                             "MAC地址: %3\n"
                                             "有效期: %4 至 %5")
                                         .arg(QFileInfo(outputPath).fileName())
                                         .arg(version)
                                         .arg(normalizedMac)
                                         .arg(issueDate.toString("yyyy-MM-dd"))
                                         .arg(expireDate.toString("yyyy-MM-dd"));

            QMessageBox::information(this, "成功", successMessage);
            LOG_INFO("LICENSE", QString("授权文件生成成功: %1").arg(outputPath));

        } else {
            // 失败时显示错误弹窗
            QMessageBox::critical(this, "错误",
                                  QString("授权文件生成失败:\n%1").arg(generator.getLastError()));
            LOG_ERROR("LICENSE", QString("授权文件生成失败: %1").arg(generator.getLastError()));
        }

        // 恢复UI状态
        ui->createLicenseButton->setEnabled(true);
        ui->statusbar->clearMessage();
        ui->keyProgressBar->setVisible(false);
    });
}

QString MainWindow::normalizeMacAddress(const QString &mac)
{
    // 移除非十六进制字符
    QString normalized = mac;
    normalized.remove(QRegularExpression("[^0-9A-Fa-f]"));

    // 检查长度（应该是12个字符）
    if (normalized.length() != 12) {
        return QString();
    }

    // 转换为标准格式：00:11:22:33:44:55
    QString result;
    for (int i = 0; i < normalized.length(); i += 2) {
        if (!result.isEmpty()) {
            result += "-";
        }
        result += normalized.mid(i, 2).toUpper();
    }

    return result;
}

void MainWindow::onBrowseLicenseOutputClicked()
{
    QString defaultDir = QCoreApplication::applicationDirPath() + "/licenses";
    QDir dir(defaultDir);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString fileName = QFileDialog::getSaveFileName(
        this,
        "保存授权文件",
        defaultDir + "/license.lic",
        "授权文件 (*.lic);;所有文件 (*.*)"
        );

    if (!fileName.isEmpty()) {
        ui->outputPathEdit->setText(fileName);
        LOG_INFO("UI", QString("选择保存路径: %1").arg(fileName));
    }
}

void MainWindow::onVerifyLicenseClicked()
{
    QString licensePath = ui->licenseFileEdit->text();
    if (licensePath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择授权文件");
        return;
    }

    QString macAddress = ui->validateMacEdit->text();

    LOG_INFO("VALIDATE", QString("开始验证授权文件: %1").arg(licensePath));
    ui->statusbar->showMessage("正在验证授权...");

    LicenseValidator validator;
    LicenseValidator::ValidatedInfo result = validator.validateLicenseFile(licensePath, macAddress);

    // 显示验证结果
    if (result.isValid) {
        // 计算剩余天数（确保为正数）
        QDateTime now = QDateTime::currentDateTime();
        int daysLeft = now.daysTo(result.expireDate);

        // 如果已经过期，daysLeft会是负数
        if (daysLeft < 0) {
            daysLeft = 0;
        }

        // 填充到各个文本框中
        ui->parsedVersionEdit->setText(result.version);
        ui->parsedIssueDateEdit->setText(result.issueDate.toString("yyyy-MM-dd"));
        ui->parsedExpireDateEdit->setText(result.expireDate.toString("yyyy-MM-dd"));
        ui->parsedMacEdit->setText(result.macAddress);

        // 设置验证状态和样式（包含天数）
        QString statusText;
        QString color;

        if (daysLeft == 0) {
            statusText = "已过期";
            color = "#e74c3c"; // 红色
        } else if (daysLeft <= 7) {
            statusText = QString("即将过期 (%1天)").arg(daysLeft);
            color = "#f39c12"; // 橙色
        } else {
            statusText = QString("有效 (%1天)").arg(daysLeft);
            color = "#27ae60"; // 绿色
        }

        ui->parsedStatusEdit->setText(statusText);
        ui->parsedStatusEdit->setStyleSheet(QString(
                                                "QLineEdit {"
                                                "    font-weight: bold;"
                                                "    padding: 6px;"
                                                "    border: 2px solid %1;"
                                                "    background-color: %1;"
                                                "    color: white;"
                                                "    border-radius: 3px;"
                                                "}"
                                                ).arg(color));

        // 显示弹窗信息
        QString infoText = QString("✅ 授权验证通过！\n\n"
                                   "版本号: %1\n"
                                   "MAC地址: %2\n"
                                   "签发日期: %3\n"
                                   "过期日期: %4\n"
                                   "剩余天数: %5天")
                               .arg(result.version)
                               .arg(result.macAddress)
                               .arg(result.issueDate.toString("yyyy-MM-dd"))
                               .arg(result.expireDate.toString("yyyy-MM-dd"))
                               .arg(daysLeft);

        // 根据剩余天数显示不同颜色的文本
        if (daysLeft == 0) {
            QMessageBox::information(this, "授权验证", "✅ 授权验证通过！\n\n⚠️ 警告：授权已过期！");
        } else if (daysLeft <= 7) {
            QString daysLeftmess = QString("✅ 授权验证通过！\n\n⚠️ 注意：剩余%1天，授权即将过期！").arg(daysLeft);
            QMessageBox::information(this, "授权验证", daysLeftmess);
        } else {
            QMessageBox::information(this, "授权验证", infoText);
        }

        LOG_INFO("VALIDATE", QString("授权验证通过，剩余%1天").arg(daysLeft));
        ui->statusbar->showMessage(QString("授权验证通过，剩余%1天").arg(daysLeft), 5000);

    } else {
        // 验证失败，清空文本框并显示错误
        clearValidationFields();

        QString errorText = QString("❌ 授权验证失败！\n\n错误信息:\n%1").arg(result.errorMessage);
        LOG_ERROR("VALIDATE", errorText);

        ui->parsedStatusEdit->setText("验证失败");
        ui->parsedStatusEdit->setStyleSheet(
            "QLineEdit {"
            "    font-weight: bold;"
            "    padding: 6px;"
            "    border: 2px solid #e74c3c;"
            "    background-color: #e74c3c;"
            "    color: white;"
            "    border-radius: 3px;"
            "}"
            );

        QMessageBox::critical(this, "验证失败", result.errorMessage);
        ui->statusbar->showMessage("授权验证失败", 3000);
    }
}

// 清空验证字段的辅助函数
void MainWindow::clearValidationFields()
{
    ui->parsedVersionEdit->clear();
    ui->parsedIssueDateEdit->clear();
    ui->parsedExpireDateEdit->clear();
    ui->parsedMacEdit->clear();

    // 重置状态框样式
    ui->parsedStatusEdit->clear();
    ui->parsedStatusEdit->setStyleSheet(
        "QLineEdit {"
        "    font-weight: bold;"
        "    padding: 2px;"
        "}"
        );
}

void MainWindow::onBrowseLicenseFileClicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "选择授权文件",
        QCoreApplication::applicationDirPath(),
        "授权文件 (*.lic);;所有文件 (*.*)"
        );

    if (!fileName.isEmpty()) {
        ui->licenseFileEdit->setText(fileName);
        LOG_INFO("UI", (QString("选择授权文件: %1").arg(fileName)));
    }
}

void MainWindow::onClearLogClicked()
{
    LogManager::instance().clearDisplay();
}

void MainWindow::onExportLogClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "导出日志",
                                                    QDir::homePath() + "/license_log.txt",
                                                    "文本文件 (*.txt);;所有文件 (*.*)");
    if (!fileName.isEmpty()) {
        if (LogManager::instance().exportLog(fileName)) {
            LOG_INFO("LOG", QString("日志已导出到: %1").arg(fileName));
            QMessageBox::information(this, "成功", "日志导出成功");
        } else {
            LOG_ERROR("LOG", "日志导出失败");
            QMessageBox::warning(this, "失败", "日志导出失败");
        }
    }
}

void MainWindow::onLogLevelChanged(int index)
{
    int level = ui->logLevelCombo->itemData(index).toInt();
    LogManager::instance().setDisplayLevel(static_cast<LogManager::LogLevel>(level));
}

void MainWindow::updateStatusBar()
{
    QString status = QString("就绪 | 时间: %1")
                         .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    ui->statusbar->showMessage(status);
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "关于国密授权管理系统",
                       "<h3>国密授权管理系统</h3>"
                       "<p>版本: 1.0</p>"
                       "<p>基于GMSSL的SM2/SM3/SM4国密算法</p>"
                       "<p>用于生成和验证软件授权文件</p>"
                       "<p>@ 2026 国密授权管理系统</p>");
}

void MainWindow::showConfigDialog()
{
    ConfigManager &config = ConfigManager::instance();
    config.loadConfig(); // 每次生成都加载最新的配置密钥

    QString privateKeyPath = config.getPrivateKeyPath();
    QString pubKeyPath = config.getPublicKeyPath();
    QString sm4KeyPath = config.getSm4KeyPath();
    QString password = config.getSm2KeyPassword();

    // 拼接configInfo
    QString configInfo = QString("当前配置:\n\n"
                                 "私钥路径: %1\n"
                                 "公钥路径: %2\n"
                                 "SM4密钥路径: %3\n")
                             .arg(privateKeyPath.isEmpty() || !QFile::exists(privateKeyPath) ?
                                      "❌ 不存在" : privateKeyPath)
                             .arg(pubKeyPath.isEmpty() || !QFile::exists(pubKeyPath) ?
                                      "❌ 不存在" : pubKeyPath)
                             .arg(sm4KeyPath.isEmpty() || !QFile::exists(sm4KeyPath) ?
                                      "❌ 不存在" : sm4KeyPath);

    QMessageBox::about(this, "配置管理", configInfo);
}

void MainWindow::showKeyConfigDialog()
{
    KeyConfigDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // 配置保存成功，可以在这里进行其他操作
        ui->logTextEdit->append("<font color='green'>[INFO] 密钥配置已更新</font>");
    }
}

// 添加缺少的 showMessage 方法
void MainWindow::showMessage(const QString &message, bool isError)
{
    if (isError) {
        LOG_ERROR("UI", message);
        QMessageBox::warning(this, "警告", message);
    } else {
        LOG_INFO("UI", message);
        ui->statusbar->showMessage(message, 3000);
    }
}

