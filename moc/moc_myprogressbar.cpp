/****************************************************************************
** Meta object code from reading C++ file 'myprogressbar.h'
**
** Created: Tue May 14 22:35:06 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/myprogressbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myprogressbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myProgressBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      34,   28,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myProgressBar[] = {
    "myProgressBar\0\0UpdateData()\0value\0"
    "setValue(int)\0"
};

void myProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myProgressBar *_t = static_cast<myProgressBar *>(_o);
        switch (_id) {
        case 0: _t->UpdateData(); break;
        case 1: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myProgressBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myProgressBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myProgressBar,
      qt_meta_data_myProgressBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myProgressBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myProgressBar))
        return static_cast<void*>(const_cast< myProgressBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int myProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
