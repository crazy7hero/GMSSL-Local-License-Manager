/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *keyTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *keyGenerationGroup;
    QGridLayout *gridLayout_2;
    QLabel *label_keyDir;
    QLineEdit *keyDirEdit;
    QPushButton *browseKeyDirButton;
    QLabel *label_password;
    QLineEdit *keyPasswordEdit;
    QCheckBox *showPasswordCheck;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *generateKeysButton;
    QProgressBar *keyProgressBar;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QSpacerItem *verticalSpacer;
    QWidget *licenseTab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *licenseInfoGroup;
    QGridLayout *gridLayout_4;
    QLabel *label_version;
    QLineEdit *versionEdit;
    QLabel *label_mac;
    QLineEdit *macAddressEdit;
    QLabel *label_issue;
    QDateTimeEdit *issueDateEdit;
    QLabel *label_expire;
    QDateTimeEdit *expireDateEdit;
    QGroupBox *outputGroup;
    QGridLayout *gridLayout_5;
    QLabel *label_output;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *outputPathEdit;
    QPushButton *browseLicenseOutputButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *createLicenseButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *validateTab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *licenseFileGroup;
    QGridLayout *gridLayout_6;
    QLabel *label_licenseFile;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *licenseFileEdit;
    QPushButton *browseLicenseFileButton;
    QLabel *label_validateMac;
    QLineEdit *validateMacEdit;
    QPushButton *verifyLicenseButton;
    QGroupBox *validationResultGroup;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLineEdit *parsedVersionEdit;
    QLabel *label_8;
    QLineEdit *parsedIssueDateEdit;
    QLabel *label_9;
    QLineEdit *parsedExpireDateEdit;
    QLabel *label_10;
    QLineEdit *parsedMacEdit;
    QLabel *label_11;
    QLineEdit *parsedStatusEdit;
    QWidget *logTab;
    QVBoxLayout *verticalLayout_61;
    QHBoxLayout *horizontalLayout;
    QLabel *label_logLevel;
    QComboBox *logLevelCombo;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearLogButton;
    QPushButton *exportLogButton;
    QTextEdit *logTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        keyTab = new QWidget();
        keyTab->setObjectName(QString::fromUtf8("keyTab"));
        verticalLayout_2 = new QVBoxLayout(keyTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        keyGenerationGroup = new QGroupBox(keyTab);
        keyGenerationGroup->setObjectName(QString::fromUtf8("keyGenerationGroup"));
        gridLayout_2 = new QGridLayout(keyGenerationGroup);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_keyDir = new QLabel(keyGenerationGroup);
        label_keyDir->setObjectName(QString::fromUtf8("label_keyDir"));
        label_keyDir->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_keyDir, 0, 0, 1, 1);

        keyDirEdit = new QLineEdit(keyGenerationGroup);
        keyDirEdit->setObjectName(QString::fromUtf8("keyDirEdit"));

        gridLayout_2->addWidget(keyDirEdit, 0, 1, 1, 1);

        browseKeyDirButton = new QPushButton(keyGenerationGroup);
        browseKeyDirButton->setObjectName(QString::fromUtf8("browseKeyDirButton"));

        gridLayout_2->addWidget(browseKeyDirButton, 0, 2, 1, 1);

        label_password = new QLabel(keyGenerationGroup);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_password, 1, 0, 1, 1);

        keyPasswordEdit = new QLineEdit(keyGenerationGroup);
        keyPasswordEdit->setObjectName(QString::fromUtf8("keyPasswordEdit"));
        keyPasswordEdit->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(keyPasswordEdit, 1, 1, 1, 1);

        showPasswordCheck = new QCheckBox(keyGenerationGroup);
        showPasswordCheck->setObjectName(QString::fromUtf8("showPasswordCheck"));

        gridLayout_2->addWidget(showPasswordCheck, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        generateKeysButton = new QPushButton(keyGenerationGroup);
        generateKeysButton->setObjectName(QString::fromUtf8("generateKeysButton"));
        generateKeysButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-weight: bold;\n"
"    padding: 8px;\n"
"    background-color: #9b59b6;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #8e44ad;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #7d3c98;\n"
"}"));

        horizontalLayout_2->addWidget(generateKeysButton);

        keyProgressBar = new QProgressBar(keyGenerationGroup);
        keyProgressBar->setObjectName(QString::fromUtf8("keyProgressBar"));
        keyProgressBar->setVisible(false);
        keyProgressBar->setTextVisible(true);

        horizontalLayout_2->addWidget(keyProgressBar);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 3);


        verticalLayout_2->addWidget(keyGenerationGroup);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        groupBox_2 = new QGroupBox(keyTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_6->addWidget(label_16);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_6->addWidget(label_17);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_6->addWidget(label_18);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(keyTab, QString());
        licenseTab = new QWidget();
        licenseTab->setObjectName(QString::fromUtf8("licenseTab"));
        verticalLayout_3 = new QVBoxLayout(licenseTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        licenseInfoGroup = new QGroupBox(licenseTab);
        licenseInfoGroup->setObjectName(QString::fromUtf8("licenseInfoGroup"));
        gridLayout_4 = new QGridLayout(licenseInfoGroup);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_version = new QLabel(licenseInfoGroup);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_version, 0, 0, 1, 1);

        versionEdit = new QLineEdit(licenseInfoGroup);
        versionEdit->setObjectName(QString::fromUtf8("versionEdit"));

        gridLayout_4->addWidget(versionEdit, 0, 1, 1, 1);

        label_mac = new QLabel(licenseInfoGroup);
        label_mac->setObjectName(QString::fromUtf8("label_mac"));
        label_mac->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_mac, 1, 0, 1, 1);

        macAddressEdit = new QLineEdit(licenseInfoGroup);
        macAddressEdit->setObjectName(QString::fromUtf8("macAddressEdit"));

        gridLayout_4->addWidget(macAddressEdit, 1, 1, 1, 1);

        label_issue = new QLabel(licenseInfoGroup);
        label_issue->setObjectName(QString::fromUtf8("label_issue"));
        label_issue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_issue, 2, 0, 1, 1);

        issueDateEdit = new QDateTimeEdit(licenseInfoGroup);
        issueDateEdit->setObjectName(QString::fromUtf8("issueDateEdit"));
        issueDateEdit->setDate(QDate(2026, 1, 15));
        issueDateEdit->setCalendarPopup(true);

        gridLayout_4->addWidget(issueDateEdit, 2, 1, 1, 1);

        label_expire = new QLabel(licenseInfoGroup);
        label_expire->setObjectName(QString::fromUtf8("label_expire"));
        label_expire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_expire, 3, 0, 1, 1);

        expireDateEdit = new QDateTimeEdit(licenseInfoGroup);
        expireDateEdit->setObjectName(QString::fromUtf8("expireDateEdit"));
        expireDateEdit->setDate(QDate(2026, 12, 31));
        expireDateEdit->setCalendarPopup(true);

        gridLayout_4->addWidget(expireDateEdit, 3, 1, 1, 1);


        verticalLayout_3->addWidget(licenseInfoGroup);

        outputGroup = new QGroupBox(licenseTab);
        outputGroup->setObjectName(QString::fromUtf8("outputGroup"));
        gridLayout_5 = new QGridLayout(outputGroup);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_output = new QLabel(outputGroup);
        label_output->setObjectName(QString::fromUtf8("label_output"));
        label_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_output, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        outputPathEdit = new QLineEdit(outputGroup);
        outputPathEdit->setObjectName(QString::fromUtf8("outputPathEdit"));

        horizontalLayout_5->addWidget(outputPathEdit);

        browseLicenseOutputButton = new QPushButton(outputGroup);
        browseLicenseOutputButton->setObjectName(QString::fromUtf8("browseLicenseOutputButton"));

        horizontalLayout_5->addWidget(browseLicenseOutputButton);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 1, 1, 1);


        verticalLayout_3->addWidget(outputGroup);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        createLicenseButton = new QPushButton(licenseTab);
        createLicenseButton->setObjectName(QString::fromUtf8("createLicenseButton"));
        createLicenseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-weight: bold;\n"
"    padding: 8px;\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}"));

        verticalLayout_3->addWidget(createLicenseButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        tabWidget->addTab(licenseTab, QString());
        validateTab = new QWidget();
        validateTab->setObjectName(QString::fromUtf8("validateTab"));
        verticalLayout_4 = new QVBoxLayout(validateTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        licenseFileGroup = new QGroupBox(validateTab);
        licenseFileGroup->setObjectName(QString::fromUtf8("licenseFileGroup"));
        gridLayout_6 = new QGridLayout(licenseFileGroup);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_licenseFile = new QLabel(licenseFileGroup);
        label_licenseFile->setObjectName(QString::fromUtf8("label_licenseFile"));
        label_licenseFile->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_licenseFile, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        licenseFileEdit = new QLineEdit(licenseFileGroup);
        licenseFileEdit->setObjectName(QString::fromUtf8("licenseFileEdit"));

        horizontalLayout_6->addWidget(licenseFileEdit);

        browseLicenseFileButton = new QPushButton(licenseFileGroup);
        browseLicenseFileButton->setObjectName(QString::fromUtf8("browseLicenseFileButton"));

        horizontalLayout_6->addWidget(browseLicenseFileButton);


        gridLayout_6->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        label_validateMac = new QLabel(licenseFileGroup);
        label_validateMac->setObjectName(QString::fromUtf8("label_validateMac"));
        label_validateMac->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_validateMac, 1, 0, 1, 1);

        validateMacEdit = new QLineEdit(licenseFileGroup);
        validateMacEdit->setObjectName(QString::fromUtf8("validateMacEdit"));

        gridLayout_6->addWidget(validateMacEdit, 1, 1, 1, 1);


        verticalLayout_4->addWidget(licenseFileGroup);

        verifyLicenseButton = new QPushButton(validateTab);
        verifyLicenseButton->setObjectName(QString::fromUtf8("verifyLicenseButton"));
        verifyLicenseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-weight: bold;\n"
"    padding: 8px;\n"
"    background-color: #2196F3;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1976D2;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1;\n"
"}"));

        verticalLayout_4->addWidget(verifyLicenseButton);

        validationResultGroup = new QGroupBox(validateTab);
        validationResultGroup->setObjectName(QString::fromUtf8("validationResultGroup"));
        gridLayout_3 = new QGridLayout(validationResultGroup);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_7 = new QLabel(validationResultGroup);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        parsedVersionEdit = new QLineEdit(validationResultGroup);
        parsedVersionEdit->setObjectName(QString::fromUtf8("parsedVersionEdit"));
        parsedVersionEdit->setReadOnly(true);

        gridLayout_3->addWidget(parsedVersionEdit, 0, 1, 1, 1);

        label_8 = new QLabel(validationResultGroup);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        parsedIssueDateEdit = new QLineEdit(validationResultGroup);
        parsedIssueDateEdit->setObjectName(QString::fromUtf8("parsedIssueDateEdit"));
        parsedIssueDateEdit->setReadOnly(true);

        gridLayout_3->addWidget(parsedIssueDateEdit, 1, 1, 1, 1);

        label_9 = new QLabel(validationResultGroup);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        parsedExpireDateEdit = new QLineEdit(validationResultGroup);
        parsedExpireDateEdit->setObjectName(QString::fromUtf8("parsedExpireDateEdit"));
        parsedExpireDateEdit->setReadOnly(true);

        gridLayout_3->addWidget(parsedExpireDateEdit, 2, 1, 1, 1);

        label_10 = new QLabel(validationResultGroup);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        parsedMacEdit = new QLineEdit(validationResultGroup);
        parsedMacEdit->setObjectName(QString::fromUtf8("parsedMacEdit"));
        parsedMacEdit->setReadOnly(true);

        gridLayout_3->addWidget(parsedMacEdit, 3, 1, 1, 1);

        label_11 = new QLabel(validationResultGroup);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_11, 4, 0, 1, 1);

        parsedStatusEdit = new QLineEdit(validationResultGroup);
        parsedStatusEdit->setObjectName(QString::fromUtf8("parsedStatusEdit"));
        parsedStatusEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"				font-weight: bold;\n"
"				padding: 2px;}"));
        parsedStatusEdit->setReadOnly(true);

        gridLayout_3->addWidget(parsedStatusEdit, 4, 1, 1, 1);


        verticalLayout_4->addWidget(validationResultGroup);

        tabWidget->addTab(validateTab, QString());
        logTab = new QWidget();
        logTab->setObjectName(QString::fromUtf8("logTab"));
        verticalLayout_61 = new QVBoxLayout(logTab);
        verticalLayout_61->setObjectName(QString::fromUtf8("verticalLayout_61"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_logLevel = new QLabel(logTab);
        label_logLevel->setObjectName(QString::fromUtf8("label_logLevel"));
        label_logLevel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_logLevel);

        logLevelCombo = new QComboBox(logTab);
        logLevelCombo->setObjectName(QString::fromUtf8("logLevelCombo"));

        horizontalLayout->addWidget(logLevelCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearLogButton = new QPushButton(logTab);
        clearLogButton->setObjectName(QString::fromUtf8("clearLogButton"));

        horizontalLayout->addWidget(clearLogButton);

        exportLogButton = new QPushButton(logTab);
        exportLogButton->setObjectName(QString::fromUtf8("exportLogButton"));

        horizontalLayout->addWidget(exportLogButton);


        verticalLayout_61->addLayout(horizontalLayout);

        logTextEdit = new QTextEdit(logTab);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(9);
        logTextEdit->setFont(font);
        logTextEdit->setReadOnly(true);

        verticalLayout_61->addWidget(logTextEdit);

        tabWidget->addTab(logTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\233\275\345\257\206\346\216\210\346\235\203\347\256\241\347\220\206\345\231\250", nullptr));
        keyGenerationGroup->setTitle(QCoreApplication::translate("MainWindow", "\345\257\206\351\222\245\347\224\237\346\210\220", nullptr));
        label_keyDir->setText(QCoreApplication::translate("MainWindow", "\345\257\206\351\222\245\347\233\256\345\275\225:", nullptr));
        keyDirEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\257\206\351\222\245\344\277\235\345\255\230\347\233\256\345\275\225", nullptr));
        browseKeyDirButton->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "\345\257\206\351\222\245\345\257\206\347\240\201:", nullptr));
        showPasswordCheck->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        generateKeysButton->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\345\257\206\351\222\245 (SM2/SM4)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\260\206\347\224\237\346\210\220\344\273\245\344\270\213\345\257\206\351\222\245\346\226\207\344\273\266", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\342\200\242 sm4_key.bin - SM4\345\257\271\347\247\260\345\257\206\351\222\245\357\274\21016\345\255\227\350\212\202\357\274\211", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\342\200\242 sm2_private.pem - SM2\347\247\201\351\222\245\357\274\210PEM\346\240\274\345\274\217\357\274\211", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\342\200\242 sm2_public.pem - SM2\345\205\254\351\222\245\357\274\210PEM\346\240\274\345\274\217\357\274\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(keyTab), QCoreApplication::translate("MainWindow", "\345\257\206\351\222\245\347\256\241\347\220\206", nullptr));
        licenseInfoGroup->setTitle(QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\344\277\241\346\201\257", nullptr));
        label_version->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\345\217\267:", nullptr));
        versionEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\276\213\345\246\202\357\274\2321.0 \346\210\226 2.0", nullptr));
        label_mac->setText(QCoreApplication::translate("MainWindow", "MAC\345\234\260\345\235\200:", nullptr));
        macAddressEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\276\213\345\246\202\357\274\23200-11-22-33-44-55 \346\210\226 00:11:22:33:44:55", nullptr));
        label_issue->setText(QCoreApplication::translate("MainWindow", "\347\255\276\345\217\221\346\227\245\346\234\237:", nullptr));
        issueDateEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd", nullptr));
        label_expire->setText(QCoreApplication::translate("MainWindow", "\345\210\260\346\234\237\346\227\245\346\234\237:", nullptr));
        expireDateEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy-MM-dd", nullptr));
        outputGroup->setTitle(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\350\256\276\347\275\256", nullptr));
        label_output->setText(QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\346\226\207\344\273\266\350\267\257\345\276\204:", nullptr));
        outputPathEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\216\210\346\235\203\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        browseLicenseOutputButton->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
        createLicenseButton->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\216\210\346\235\203\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(licenseTab), QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\347\224\237\346\210\220", nullptr));
        licenseFileGroup->setTitle(QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\346\226\207\344\273\266", nullptr));
        label_licenseFile->setText(QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\346\226\207\344\273\266:", nullptr));
        licenseFileEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\216\210\346\235\203\346\226\207\344\273\266", nullptr));
        browseLicenseFileButton->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
        label_validateMac->setText(QCoreApplication::translate("MainWindow", "MAC\345\234\260\345\235\200:", nullptr));
        validateMacEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "MAC\345\234\260\345\235\200", nullptr));
        verifyLicenseButton->setText(QCoreApplication::translate("MainWindow", "\351\252\214\350\257\201\346\216\210\346\235\203", nullptr));
        validationResultGroup->setTitle(QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\344\277\241\346\201\257", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\345\217\267:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\347\255\276\345\217\221\346\227\245\346\234\237:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\210\260\346\234\237\346\227\245\346\234\237:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267MAC\345\234\260\345\235\200:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\234\211\346\225\210\346\234\237\347\212\266\346\200\201:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(validateTab), QCoreApplication::translate("MainWindow", "\346\216\210\346\235\203\351\252\214\350\257\201", nullptr));
        label_logLevel->setText(QCoreApplication::translate("MainWindow", "\346\227\245\345\277\227\347\272\247\345\210\253:", nullptr));
        clearLogButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        exportLogButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\346\227\245\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
