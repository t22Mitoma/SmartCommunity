/****************************************************************************
** Meta object code from reading C++ file 'wuyecheweichuzu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IntelligentCommunity/wuyecheweichuzu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wuyecheweichuzu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Wuyecheweichuzu_t {
    QByteArrayData data[7];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Wuyecheweichuzu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Wuyecheweichuzu_t qt_meta_stringdata_Wuyecheweichuzu = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Wuyecheweichuzu"
QT_MOC_LITERAL(1, 16, 27), // "on_selectpushButton_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 24), // "on_yespushButton_clicked"
QT_MOC_LITERAL(4, 70, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(5, 91, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 103, 5) // "index"

    },
    "Wuyecheweichuzu\0on_selectpushButton_clicked\0"
    "\0on_yespushButton_clicked\0"
    "on_tableView_clicked\0QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Wuyecheweichuzu[] = {

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
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void Wuyecheweichuzu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Wuyecheweichuzu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_selectpushButton_clicked(); break;
        case 1: _t->on_yespushButton_clicked(); break;
        case 2: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Wuyecheweichuzu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Wuyecheweichuzu.data,
    qt_meta_data_Wuyecheweichuzu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Wuyecheweichuzu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Wuyecheweichuzu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Wuyecheweichuzu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Wuyecheweichuzu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
