/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "onGenerateKeysClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "onBrowseKeyDirClicked"
QT_MOC_LITERAL(4, 56, 22), // "onCreateLicenseClicked"
QT_MOC_LITERAL(5, 79, 28), // "onBrowseLicenseOutputClicked"
QT_MOC_LITERAL(6, 108, 22), // "onVerifyLicenseClicked"
QT_MOC_LITERAL(7, 131, 26), // "onBrowseLicenseFileClicked"
QT_MOC_LITERAL(8, 158, 17), // "onClearLogClicked"
QT_MOC_LITERAL(9, 176, 18), // "onExportLogClicked"
QT_MOC_LITERAL(10, 195, 17), // "onLogLevelChanged"
QT_MOC_LITERAL(11, 213, 5), // "index"
QT_MOC_LITERAL(12, 219, 15), // "updateStatusBar"
QT_MOC_LITERAL(13, 235, 9), // "showAbout"
QT_MOC_LITERAL(14, 245, 16), // "showConfigDialog"
QT_MOC_LITERAL(15, 262, 14), // "checkKeysExist"
QT_MOC_LITERAL(16, 277, 7), // "dirPath"
QT_MOC_LITERAL(17, 285, 16), // "confirmOverwrite"
QT_MOC_LITERAL(18, 302, 21), // "clearValidationFields"
QT_MOC_LITERAL(19, 324, 19) // "showKeyConfigDialog"

    },
    "MainWindow\0onGenerateKeysClicked\0\0"
    "onBrowseKeyDirClicked\0onCreateLicenseClicked\0"
    "onBrowseLicenseOutputClicked\0"
    "onVerifyLicenseClicked\0"
    "onBrowseLicenseFileClicked\0onClearLogClicked\0"
    "onExportLogClicked\0onLogLevelChanged\0"
    "index\0updateStatusBar\0showAbout\0"
    "showConfigDialog\0checkKeysExist\0dirPath\0"
    "confirmOverwrite\0clearValidationFields\0"
    "showKeyConfigDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    1,  102,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    1,  108,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onGenerateKeysClicked(); break;
        case 1: _t->onBrowseKeyDirClicked(); break;
        case 2: _t->onCreateLicenseClicked(); break;
        case 3: _t->onBrowseLicenseOutputClicked(); break;
        case 4: _t->onVerifyLicenseClicked(); break;
        case 5: _t->onBrowseLicenseFileClicked(); break;
        case 6: _t->onClearLogClicked(); break;
        case 7: _t->onExportLogClicked(); break;
        case 8: _t->onLogLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateStatusBar(); break;
        case 10: _t->showAbout(); break;
        case 11: _t->showConfigDialog(); break;
        case 12: { bool _r = _t->checkKeysExist((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->confirmOverwrite((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->clearValidationFields(); break;
        case 15: _t->showKeyConfigDialog(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
