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
    QByteArrayData data[12];
    char stringdata0[142];
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
QT_MOC_LITERAL(4, 25, 8), // "execDraw"
QT_MOC_LITERAL(5, 34, 18), // "execShowExecStatus"
QT_MOC_LITERAL(6, 53, 32), // "execHorizontalSliderValueChanged"
QT_MOC_LITERAL(7, 86, 1), // "x"
QT_MOC_LITERAL(8, 88, 12), // "exexXChanged"
QT_MOC_LITERAL(9, 101, 12), // "exexYChanged"
QT_MOC_LITERAL(10, 114, 13), // "exexXRejected"
QT_MOC_LITERAL(11, 128, 13) // "exexYRejected"

    },
    "fmView\0showExecStatus\0\0s\0execDraw\0"
    "execShowExecStatus\0execHorizontalSliderValueChanged\0"
    "x\0exexXChanged\0exexYChanged\0exexXRejected\0"
    "exexYRejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fmView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x08 /* Private */,
       5,    1,   60,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    7,
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
        case 1: _t->execDraw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->execShowExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->execHorizontalSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->exexXChanged(); break;
        case 5: _t->exexYChanged(); break;
        case 6: _t->exexXRejected(); break;
        case 7: _t->exexYRejected(); break;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void fmView::showExecStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
