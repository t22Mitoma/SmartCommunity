/****************************************************************************
** Meta object code from reading C++ file 'worker_mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IntelligentCommunity/worker_mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker_mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_worker_MainWindow_t {
    QByteArrayData data[9];
    char stringdata0[175];
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
QT_MOC_LITERAL(8, 153, 21) // "on_action_6_triggered"

    },
    "worker_MainWindow\0on_action_triggered\0"
    "\0on_actionrenshi_triggered\0"
    "on_action_2_triggered\0on_action_3_triggered\0"
    "on_action_4_triggered\0on_action_5_triggered\0"
    "on_action_6_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_worker_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
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
        worker_MainWindow *_t = static_cast<worker_MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_triggered(); break;
        case 1: _t->on_actionrenshi_triggered(); break;
        case 2: _t->on_action_2_triggered(); break;
        case 3: _t->on_action_3_triggered(); break;
        case 4: _t->on_action_4_triggered(); break;
        case 5: _t->on_action_5_triggered(); break;
        case 6: _t->on_action_6_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject worker_MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_worker_MainWindow.data,
      qt_meta_data_worker_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *worker_MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *worker_MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_worker_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< worker_MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int worker_MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
