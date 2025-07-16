/****************************************************************************
** Meta object code from reading C++ file 'worker_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IntelligentCommunity/worker_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_worker_MainWindow_t {
    QByteArrayData data[11];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_worker_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_worker_MainWindow_t qt_meta_stringdata_worker_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "worker_MainWindow"
QT_MOC_LITERAL(1, 18, 19), // "on_action_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "on_actionrenshi_triggered"
QT_MOC_LITERAL(4, 65, 21), // "on_action_2_triggered"
QT_MOC_LITERAL(5, 87, 21), // "on_action_3_triggered"
QT_MOC_LITERAL(6, 109, 21), // "on_action_4_triggered"
QT_MOC_LITERAL(7, 131, 21), // "on_action_5_triggered"
QT_MOC_LITERAL(8, 153, 21), // "on_action_6_triggered"
QT_MOC_LITERAL(9, 175, 21), // "on_action_7_triggered"
QT_MOC_LITERAL(10, 197, 21) // "on_action_8_triggered"

    },
    "worker_MainWindow\0on_action_triggered\0"
    "\0on_actionrenshi_triggered\0"
    "on_action_2_triggered\0on_action_3_triggered\0"
    "on_action_4_triggered\0on_action_5_triggered\0"
    "on_action_6_triggered\0on_action_7_triggered\0"
    "on_action_8_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_worker_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void worker_MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<worker_MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_triggered(); break;
        case 1: _t->on_actionrenshi_triggered(); break;
        case 2: _t->on_action_2_triggered(); break;
        case 3: _t->on_action_3_triggered(); break;
        case 4: _t->on_action_4_triggered(); break;
        case 5: _t->on_action_5_triggered(); break;
        case 6: _t->on_action_6_triggered(); break;
        case 7: _t->on_action_7_triggered(); break;
        case 8: _t->on_action_8_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject worker_MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_worker_MainWindow.data,
    qt_meta_data_worker_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *worker_MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *worker_MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_worker_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int worker_MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
