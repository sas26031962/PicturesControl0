/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 4), // "draw"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 1), // "s"
QT_MOC_LITERAL(4, 19, 26), // "execActionSelectImageBegin"
QT_MOC_LITERAL(5, 46, 25), // "execActionSelectImageNext"
QT_MOC_LITERAL(6, 72, 29), // "execActionSelectImagePrevious"
QT_MOC_LITERAL(7, 102, 24), // "execActionSelectImageEnd"
QT_MOC_LITERAL(8, 127, 16), // "execActionImport"
QT_MOC_LITERAL(9, 144, 14), // "execActionLoad"
QT_MOC_LITERAL(10, 159, 25), // "execActionFormViewPicture"
QT_MOC_LITERAL(11, 185, 32), // "execListWidgetSuggestItemClicked"
QT_MOC_LITERAL(12, 218, 32), // "execActionLoadHashTagListSubject"
QT_MOC_LITERAL(13, 251, 30), // "execActionLoadHashTagListPlace"
QT_MOC_LITERAL(14, 282, 21), // "execActionRemoveMovie"
QT_MOC_LITERAL(15, 304, 18), // "execActionRotateCW"
QT_MOC_LITERAL(16, 323, 19) // "execActionRotateCCW"

    },
    "MainWindow\0draw\0\0s\0execActionSelectImageBegin\0"
    "execActionSelectImageNext\0"
    "execActionSelectImagePrevious\0"
    "execActionSelectImageEnd\0execActionImport\0"
    "execActionLoad\0execActionFormViewPicture\0"
    "execListWidgetSuggestItemClicked\0"
    "execActionLoadHashTagListSubject\0"
    "execActionLoadHashTagListPlace\0"
    "execActionRemoveMovie\0execActionRotateCW\0"
    "execActionRotateCCW"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   87,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->draw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->execActionSelectImageBegin(); break;
        case 2: _t->execActionSelectImageNext(); break;
        case 3: _t->execActionSelectImagePrevious(); break;
        case 4: _t->execActionSelectImageEnd(); break;
        case 5: _t->execActionImport(); break;
        case 6: _t->execActionLoad(); break;
        case 7: _t->execActionFormViewPicture(); break;
        case 8: _t->execListWidgetSuggestItemClicked(); break;
        case 9: _t->execActionLoadHashTagListSubject(); break;
        case 10: _t->execActionLoadHashTagListPlace(); break;
        case 11: _t->execActionRemoveMovie(); break;
        case 12: _t->execActionRotateCW(); break;
        case 13: _t->execActionRotateCCW(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::draw)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::draw(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
