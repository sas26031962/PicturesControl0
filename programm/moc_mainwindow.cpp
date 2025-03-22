/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[416];
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
QT_MOC_LITERAL(4, 19, 14), // "showExecStatus"
QT_MOC_LITERAL(5, 34, 26), // "execActionSelectImageBegin"
QT_MOC_LITERAL(6, 61, 25), // "execActionSelectImageNext"
QT_MOC_LITERAL(7, 87, 29), // "execActionSelectImagePrevious"
QT_MOC_LITERAL(8, 117, 24), // "execActionSelectImageEnd"
QT_MOC_LITERAL(9, 142, 16), // "execActionImport"
QT_MOC_LITERAL(10, 159, 14), // "execActionLoad"
QT_MOC_LITERAL(11, 174, 25), // "execActionFormViewPicture"
QT_MOC_LITERAL(12, 200, 32), // "execListWidgetSuggestItemClicked"
QT_MOC_LITERAL(13, 233, 15), // "execTimerUpdate"
QT_MOC_LITERAL(14, 249, 32), // "execActionLoadHashTagListSubject"
QT_MOC_LITERAL(15, 282, 30), // "execActionLoadHashTagListPlace"
QT_MOC_LITERAL(16, 313, 21), // "execActionRemoveMovie"
QT_MOC_LITERAL(17, 335, 18), // "execActionRotateCW"
QT_MOC_LITERAL(18, 354, 19), // "execActionRotateCCW"
QT_MOC_LITERAL(19, 374, 16), // "execSpinBoxAngle"
QT_MOC_LITERAL(20, 391, 5), // "angle"
QT_MOC_LITERAL(21, 397, 18) // "execShowExecStatus"

    },
    "MainWindow\0draw\0\0s\0showExecStatus\0"
    "execActionSelectImageBegin\0"
    "execActionSelectImageNext\0"
    "execActionSelectImagePrevious\0"
    "execActionSelectImageEnd\0execActionImport\0"
    "execActionLoad\0execActionFormViewPicture\0"
    "execListWidgetSuggestItemClicked\0"
    "execTimerUpdate\0execActionLoadHashTagListSubject\0"
    "execActionLoadHashTagListPlace\0"
    "execActionRemoveMovie\0execActionRotateCW\0"
    "execActionRotateCCW\0execSpinBoxAngle\0"
    "angle\0execShowExecStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    1,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  110,    2, 0x08 /* Private */,
       6,    0,  111,    2, 0x08 /* Private */,
       7,    0,  112,    2, 0x08 /* Private */,
       8,    0,  113,    2, 0x08 /* Private */,
       9,    0,  114,    2, 0x08 /* Private */,
      10,    0,  115,    2, 0x08 /* Private */,
      11,    0,  116,    2, 0x08 /* Private */,
      12,    0,  117,    2, 0x08 /* Private */,
      13,    0,  118,    2, 0x08 /* Private */,
      14,    0,  119,    2, 0x08 /* Private */,
      15,    0,  120,    2, 0x08 /* Private */,
      16,    0,  121,    2, 0x08 /* Private */,
      17,    0,  122,    2, 0x08 /* Private */,
      18,    0,  123,    2, 0x08 /* Private */,
      19,    1,  124,    2, 0x08 /* Private */,
      21,    1,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->draw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->execActionSelectImageBegin(); break;
        case 3: _t->execActionSelectImageNext(); break;
        case 4: _t->execActionSelectImagePrevious(); break;
        case 5: _t->execActionSelectImageEnd(); break;
        case 6: _t->execActionImport(); break;
        case 7: _t->execActionLoad(); break;
        case 8: _t->execActionFormViewPicture(); break;
        case 9: _t->execListWidgetSuggestItemClicked(); break;
        case 10: _t->execTimerUpdate(); break;
        case 11: _t->execActionLoadHashTagListSubject(); break;
        case 12: _t->execActionLoadHashTagListPlace(); break;
        case 13: _t->execActionRemoveMovie(); break;
        case 14: _t->execActionRotateCW(); break;
        case 15: _t->execActionRotateCCW(); break;
        case 16: _t->execSpinBoxAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->execShowExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::draw)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showExecStatus)) {
                *result = 1;
                return;
            }
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::draw(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::showExecStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
