/****************************************************************************
** Meta object code from reading C++ file 'fmview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../fmview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fmView_t {
    QByteArrayData data[14];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fmView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fmView_t qt_meta_stringdata_fmView = {
    {
QT_MOC_LITERAL(0, 0, 6), // "fmView"
QT_MOC_LITERAL(1, 7, 14), // "showExecStatus"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "s"
QT_MOC_LITERAL(4, 25, 18), // "shiftXValueChanged"
QT_MOC_LITERAL(5, 44, 18), // "shiftYValueChanged"
QT_MOC_LITERAL(6, 63, 8), // "execDraw"
QT_MOC_LITERAL(7, 72, 18), // "execShowExecStatus"
QT_MOC_LITERAL(8, 91, 32), // "execHorizontalSliderValueChanged"
QT_MOC_LITERAL(9, 124, 1), // "x"
QT_MOC_LITERAL(10, 126, 12), // "execXChanged"
QT_MOC_LITERAL(11, 139, 12), // "execYChanged"
QT_MOC_LITERAL(12, 152, 13), // "execXRejected"
QT_MOC_LITERAL(13, 166, 13) // "execYRejected"

    },
    "fmView\0showExecStatus\0\0s\0shiftXValueChanged\0"
    "shiftYValueChanged\0execDraw\0"
    "execShowExecStatus\0execHorizontalSliderValueChanged\0"
    "x\0execXChanged\0execYChanged\0execXRejected\0"
    "execYRejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fmView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   69,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fmView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<fmView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->shiftXValueChanged(); break;
        case 2: _t->shiftYValueChanged(); break;
        case 3: _t->execDraw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->execShowExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->execHorizontalSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->execXChanged(); break;
        case 7: _t->execYChanged(); break;
        case 8: _t->execXRejected(); break;
        case 9: _t->execYRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (fmView::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fmView::showExecStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (fmView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fmView::shiftXValueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (fmView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&fmView::shiftYValueChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject fmView::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_fmView.data,
    qt_meta_data_fmView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *fmView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fmView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_fmView.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int fmView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void fmView::showExecStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fmView::shiftXValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void fmView::shiftYValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
