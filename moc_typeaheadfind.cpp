/****************************************************************************
** Meta object code from reading C++ file 'typeaheadfind.h'
**
** Created: Sat Nov 26 18:09:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "typeaheadfind.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'typeaheadfind.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeAheadFindBar[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      30,   17,   17,   17, 0x05,
      41,   17,   17,   17, 0x05,
      52,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   17,   17,   17, 0x08,
      84,   17,   17,   17, 0x08,
      95,   17,   17,   17, 0x08,
     110,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TypeAheadFindBar[] = {
    "TypeAheadFindBar\0\0firstPage()\0lastPage()\0"
    "nextPage()\0prevPage()\0textChanged(QString)\0"
    "findNext()\0findPrevious()\0caseToggled()\0"
};

const QMetaObject TypeAheadFindBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_TypeAheadFindBar,
      qt_meta_data_TypeAheadFindBar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeAheadFindBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeAheadFindBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeAheadFindBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeAheadFindBar))
        return static_cast<void*>(const_cast< TypeAheadFindBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int TypeAheadFindBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: firstPage(); break;
        case 1: lastPage(); break;
        case 2: nextPage(); break;
        case 3: prevPage(); break;
        case 4: textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: findNext(); break;
        case 6: findPrevious(); break;
        case 7: caseToggled(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TypeAheadFindBar::firstPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TypeAheadFindBar::lastPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TypeAheadFindBar::nextPage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TypeAheadFindBar::prevPage()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
