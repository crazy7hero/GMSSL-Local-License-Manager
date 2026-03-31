QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += DEBUG

# MinGW 特殊设置
win32:mingw {
    # 强制UTF-8编码
    QMAKE_CXXFLAGS += -finput-charset=UTF-8
    QMAKE_CXXFLAGS += -fexec-charset=UTF-8

    # Unicode 支持
    DEFINES += UNICODE _UNICODE
}


    INCLUDEPATH += $$PWD/gmssl/include
    LIBS += -L$$PWD/gmssl/lib
    LIBS += -lgmssl


# 发布版本优化
CONFIG(release, debug|release) {
    #DEFINES += QT_NO_DEBUG_OUTPUT
    #QMAKE_CXXFLAGS += -O2
    DESTDIR = $$PWD/release
}else{
    #QMAKE_CXXFLAGS += -g
    DESTDIR = $$PWD/debug
}

# 源文件
SOURCES += \
    configmanager.cpp \
    gmsslcrypto.cpp \
    keyconfigdialog.cpp \
    licensegenerator.cpp \
    licensevalidator.cpp \
    logmanager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    configmanager.h \
    gmsslcrypto.h \
    keyconfigdialog.h \
    licensegenerator.h \
    licensevalidator.h \
    logmanager.h \
    mainwindow.h

FORMS += \
    keyconfigdialog.ui \
    mainwindow.ui

# 默认部署规则
target.path = $$[QT_INSTALL_EXAMPLES]/LicenseManager
INSTALLS += target
