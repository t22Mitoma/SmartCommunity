/****************************************************************************
** Meta object code from reading C++ file 'guanliyuanqingjiashenpi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IntelligentCommunity/guanliyuanqingjiashenpi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guanliyuanqingjiashenpi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_guanliyuanqingjiashenpi_t {
    QByteArrayData data[5];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_guanliyuanqingjiashenpi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_guanliyuanqingjiashenpi_t qt_meta_stringdata_guanliyuanqingjiashenpi = {
    {
QT_MOC_LITERAL(0, 0, 23), // "guanliyuanqingjiashenpi"
QT_MOC_LITERAL(1, 24, 20), // "approveSelectedLeave"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 19), // "rejectSelectedLeave"
QT_MOC_LITERAL(4, 66, 12) // "refreshTable"

    },
    "guanliyuanqingjiashenpi\0approveSelectedLeave\0"
    "\0rejectSelectedLeave\0refreshTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_guanliyuanqingjiashenpi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void guanliyuanqingjiashenpi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<guanliyuanqingjiashenpi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->approveSelectedLeave(); break;
        case 1: _t->rejectSelectedLeave(); break;
        case 2: _t->refreshTable(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject guanliyuanqingjiashenpi::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_guanliyuanqingjiashenpi.data,
    qt_meta_data_guanliyuanqingjiashenpi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *guanliyuanqingjiashenpi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *guanliyuanqingjiashenpi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_guanliyuanqingjiashenpi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int guanliyuanqingjiashenpi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
