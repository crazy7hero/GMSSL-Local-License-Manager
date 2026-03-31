// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 密钥管理标签页
    void onGenerateKeysClicked(); //生成密钥
    void onBrowseKeyDirClicked(); //生成密钥路径

    // 授权生成标签页
    void onCreateLicenseClicked(); //生成授权文件
    void onBrowseLicenseOutputClicked(); //授权文件路径


    // 授权验证标签页
    void onVerifyLicenseClicked(); //验证授权文件
    void onBrowseLicenseFileClicked(); //授权文件路径

    // 日志标签页
    void onClearLogClicked(); //清空日志
    void onExportLogClicked();// 导出日志
    void onLogLevelChanged(int index); //日志等级

    // 通用
    void updateStatusBar();//时间
    void showAbout(); //版本信息
    void showConfigDialog(); //配置信息

    bool checkKeysExist(const QString &dirPath); //密钥查询
    bool confirmOverwrite(const QString &dirPath); //文件覆盖检查
    void clearValidationFields();// 清空验证字段
    void showKeyConfigDialog(); //密钥配置界面
private:
    Ui::MainWindow *ui;

    void setupUI(); //界面初始化
    void loadConfig(); //配置文件初始化

    // 提示框
    void showMessage(const QString &message, bool isError = false);

    // mac校验
    QString normalizeMacAddress(const QString &mac);
};

#endif // MAINWINDOW_H
