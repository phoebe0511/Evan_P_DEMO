/****************************************************************************
** Meta object code from reading C++ file 'admindialog.h'
**
** Created: Thu Feb 27 18:29:22 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "admindialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdminDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   54,   54,   54, 0x08,
      55,   54,   54,   54, 0x08,
      88,   54,   54,   54, 0x08,
     129,   54,   54,   54, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdminDialog[] = {
    "AdminDialog\0on_pushButton_FingerPrint_start_clicked()\0"
    "\0on_pushButton_vfd_test_clicked()\0"
    "on_pushButton_usb_printer_test_clicked()\0"
    "on_pushButton_usb_printer_test_2_clicked()\0"
};

const QMetaObject AdminDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AdminDialog,
      qt_meta_data_AdminDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdminDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdminDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdminDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdminDialog))
        return static_cast<void*>(const_cast< AdminDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AdminDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_FingerPrint_start_clicked(); break;
        case 1: on_pushButton_vfd_test_clicked(); break;
        case 2: on_pushButton_usb_printer_test_clicked(); break;
        case 3: on_pushButton_usb_printer_test_2_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
