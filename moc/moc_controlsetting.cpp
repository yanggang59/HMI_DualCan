/****************************************************************************
** Meta object code from reading C++ file 'controlsetting.h'
**
** Created: Mon Aug 26 16:22:14 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/controlsetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      27,   15,   15,   15, 0x08,
      40,   15,   15,   15, 0x08,
      55,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ControlSetting[] = {
    "ControlSetting\0\0setvalid()\0setinvalid()\0"
    "sendPer500ms()\0sendPer1000ms()\0"
};

void ControlSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ControlSetting *_t = static_cast<ControlSetting *>(_o);
        switch (_id) {
        case 0: _t->setvalid(); break;
        case 1: _t->setinvalid(); break;
        case 2: _t->sendPer500ms(); break;
        case 3: _t->sendPer1000ms(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ControlSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ControlSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ControlSetting,
      qt_meta_data_ControlSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlSetting))
        return static_cast<void*>(const_cast< ControlSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int ControlSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
