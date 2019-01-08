/****************************************************************************
** Meta object code from reading C++ file 'fede.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fede.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fede.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FEDE_t {
    QByteArrayData data[11];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FEDE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FEDE_t qt_meta_stringdata_FEDE = {
    {
QT_MOC_LITERAL(0, 0, 4), // "FEDE"
QT_MOC_LITERAL(1, 5, 16), // "Click_pushButton"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "Click_pushButton_2"
QT_MOC_LITERAL(4, 42, 18), // "Click_pushButton_3"
QT_MOC_LITERAL(5, 61, 18), // "Click_pushButton_4"
QT_MOC_LITERAL(6, 80, 18), // "Click_pushButton_5"
QT_MOC_LITERAL(7, 99, 18), // "Click_pushButton_6"
QT_MOC_LITERAL(8, 118, 22), // "Click_pushButton_color"
QT_MOC_LITERAL(9, 141, 11), // "timerUpdate"
QT_MOC_LITERAL(10, 153, 12) // "OnBtnClicked"

    },
    "FEDE\0Click_pushButton\0\0Click_pushButton_2\0"
    "Click_pushButton_3\0Click_pushButton_4\0"
    "Click_pushButton_5\0Click_pushButton_6\0"
    "Click_pushButton_color\0timerUpdate\0"
    "OnBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FEDE[] = {

 // content:
       7,       // revision
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
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

void FEDE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FEDE *_t = static_cast<FEDE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Click_pushButton(); break;
        case 1: _t->Click_pushButton_2(); break;
        case 2: _t->Click_pushButton_3(); break;
        case 3: _t->Click_pushButton_4(); break;
        case 4: _t->Click_pushButton_5(); break;
        case 5: _t->Click_pushButton_6(); break;
        case 6: _t->Click_pushButton_color(); break;
        case 7: _t->timerUpdate(); break;
        case 8: _t->OnBtnClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FEDE::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FEDE.data,
      qt_meta_data_FEDE,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FEDE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FEDE::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FEDE.stringdata0))
        return static_cast<void*>(const_cast< FEDE*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FEDE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
