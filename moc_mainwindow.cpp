/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Feb 27 19:19:37 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   27,   34,   34, 0x05,
      35,   50,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   27,   34,   34, 0x08,
      72,   50,   34,   34, 0x08,
      89,   34,   34,   34, 0x08,
     119,   34,   34,   34, 0x08,
     149,   34,   34,   34, 0x08,
     179,   34,   34,   34, 0x08,
     209,   34,   34,   34, 0x08,
     239,   34,   34,   34, 0x08,
     269,   34,   34,   34, 0x08,
     299,   34,   34,   34, 0x08,
     329,   34,   34,   34, 0x08,
     359,   34,   34,   34, 0x08,
     390,   34,   34,   34, 0x08,
     421,   34,   34,   34, 0x08,
     452,   34,   34,   34, 0x08,
     481,   34,   34,   34, 0x08,
     511,   34,   34,   34, 0x08,
     542,   34,   34,   34, 0x08,
     571,   34,   34,   34, 0x08,
     600,   34,   34,   34, 0x08,
     629,   34,   34,   34, 0x08,
     658,   34,   34,   34, 0x08,
     687,   34,   34,   34, 0x08,
     716,   34,   34,   34, 0x08,
     745,   34,   34,   34, 0x08,
     774,   34,   34,   34, 0x08,
     803,   34,   34,   34, 0x08,
     833,   34,   34,   34, 0x08,
     863,   34,   34,   34, 0x08,
     892,   34,   34,   34, 0x08,
     922,   34,   34,   34, 0x08,
     952,  973,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0itemSelect(int)\0select\0\0"
    "numSelect(int)\0num\0doitemSelect(int)\0"
    "donumSelect(int)\0on_pushButton_item1_clicked()\0"
    "on_pushButton_item2_clicked()\0"
    "on_pushButton_item3_clicked()\0"
    "on_pushButton_item4_clicked()\0"
    "on_pushButton_item5_clicked()\0"
    "on_pushButton_item6_clicked()\0"
    "on_pushButton_item7_clicked()\0"
    "on_pushButton_item8_clicked()\0"
    "on_pushButton_item9_clicked()\0"
    "on_pushButton_item10_clicked()\0"
    "on_pushButton_item11_clicked()\0"
    "on_pushButton_item12_clicked()\0"
    "on_pushButton_num0_clicked()\0"
    "on_pushButton_num00_clicked()\0"
    "on_pushButton_num000_clicked()\0"
    "on_pushButton_num1_clicked()\0"
    "on_pushButton_num2_clicked()\0"
    "on_pushButton_num3_clicked()\0"
    "on_pushButton_num4_clicked()\0"
    "on_pushButton_num5_clicked()\0"
    "on_pushButton_num6_clicked()\0"
    "on_pushButton_num7_clicked()\0"
    "on_pushButton_num8_clicked()\0"
    "on_pushButton_num9_clicked()\0"
    "on_pushButton_enter_clicked()\0"
    "on_pushButton_admin_clicked()\0"
    "on_pushButton_exit_clicked()\0"
    "on_pushButton_clear_clicked()\0"
    "on_pushButton_print_clicked()\0"
    "receiveslot(QString)\0s\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: itemSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: numSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: doitemSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: donumSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_pushButton_item1_clicked(); break;
        case 5: on_pushButton_item2_clicked(); break;
        case 6: on_pushButton_item3_clicked(); break;
        case 7: on_pushButton_item4_clicked(); break;
        case 8: on_pushButton_item5_clicked(); break;
        case 9: on_pushButton_item6_clicked(); break;
        case 10: on_pushButton_item7_clicked(); break;
        case 11: on_pushButton_item8_clicked(); break;
        case 12: on_pushButton_item9_clicked(); break;
        case 13: on_pushButton_item10_clicked(); break;
        case 14: on_pushButton_item11_clicked(); break;
        case 15: on_pushButton_item12_clicked(); break;
        case 16: on_pushButton_num0_clicked(); break;
        case 17: on_pushButton_num00_clicked(); break;
        case 18: on_pushButton_num000_clicked(); break;
        case 19: on_pushButton_num1_clicked(); break;
        case 20: on_pushButton_num2_clicked(); break;
        case 21: on_pushButton_num3_clicked(); break;
        case 22: on_pushButton_num4_clicked(); break;
        case 23: on_pushButton_num5_clicked(); break;
        case 24: on_pushButton_num6_clicked(); break;
        case 25: on_pushButton_num7_clicked(); break;
        case 26: on_pushButton_num8_clicked(); break;
        case 27: on_pushButton_num9_clicked(); break;
        case 28: on_pushButton_enter_clicked(); break;
        case 29: on_pushButton_admin_clicked(); break;
        case 30: on_pushButton_exit_clicked(); break;
        case 31: on_pushButton_clear_clicked(); break;
        case 32: on_pushButton_print_clicked(); break;
        case 33: receiveslot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::itemSelect(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::numSelect(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
