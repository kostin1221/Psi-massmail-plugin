/****************************************************************************
** Meta object code from reading C++ file 'viewer.h'
**
** Created: Sat Nov 26 18:09:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "viewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewLog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,
      50,    8,    8,    8, 0x08,
      62,    8,    8,    8, 0x08,
      73,    8,    8,    8, 0x08,
      84,    8,    8,    8, 0x08,
      96,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViewLog[] = {
    "ViewLog\0\0,\0onClose(int,int)\0saveLog()\0"
    "updateLog()\0deleteLog()\0nextPage()\0"
    "prevPage()\0firstPage()\0lastPage()\0"
};

const QMetaObject ViewLog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ViewLog,
      qt_meta_data_ViewLog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewLog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewLog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewLog))
        return static_cast<void*>(const_cast< ViewLog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ViewLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onClose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: saveLog(); break;
        case 2: updateLog(); break;
        case 3: deleteLog(); break;
        case 4: nextPage(); break;
        case 5: prevPage(); break;
        case 6: firstPage(); break;
        case 7: lastPage(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ViewLog::onClose(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
