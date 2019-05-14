/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created: Tue May 14 22:37:12 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/mywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,    9,    9,    9, 0x08,
      41,    9,    9,    9, 0x08,
      52,    9,    9,    9, 0x08,
      63,    9,    9,    9, 0x08,
      75,    9,    9,    9, 0x08,
      92,    9,    9,    9, 0x08,
     108,  102,    9,    9, 0x08,
     131,  102,    9,    9, 0x08,
     154,  102,    9,    9, 0x08,
     181,  102,    9,    9, 0x08,
     205,  102,    9,    9, 0x08,
     228,  102,    9,    9, 0x08,
     252,  102,    9,    9, 0x08,
     284,  102,    9,    9, 0x08,
     306,  102,    9,    9, 0x08,
     329,  102,    9,    9, 0x08,
     352,  102,    9,    9, 0x08,
     379,  102,    9,    9, 0x08,
     401,  102,    9,    9, 0x08,
     424,  102,    9,    9, 0x08,
     448,  102,    9,    9, 0x08,
     473,  102,    9,    9, 0x08,
     495,  102,    9,    9, 0x08,
     518,  102,    9,    9, 0x08,
     542,  102,    9,    9, 0x08,
     559,  102,    9,    9, 0x08,
     582,  102,    9,    9, 0x08,
     602,  102,    9,    9, 0x08,
     626,  102,    9,    9, 0x08,
     646,  102,    9,    9, 0x08,
     661,  102,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_myWidget[] = {
    "myWidget\0\0sendTime(QString)\0updateTime()\0"
    "show_sys()\0hide_sys()\0close_sys()\0"
    "show_parameter()\0FeedDog()\0array\0"
    "get_eng_ti_dis(int[8])\0get_speed_data(int[8])\0"
    "get_meter_distance(int[8])\0"
    "get_motor_speed(int[8])\0get_unload_btn(int[8])\0"
    "get_valve_state(int[8])\0"
    "get_redischarge_machine(int[8])\0"
    "get_clean_fan(int[8])\0get_water_rate(int[8])\0"
    "get_weight_dry(int[8])\0"
    "get_elevator_speed(int[8])\0"
    "get_lose_rate(int[8])\0get_gear_state(int[8])\0"
    "get_throw_angle(int[8])\0"
    "get_detect_value(int[8])\0get_cut_width(int[8])\0"
    "get_real_speed(int[8])\0get_cutter_freq(int[8])\0"
    "get_feed(int[8])\0get_drum_speed(int[8])\0"
    "get_eng_thm(int[8])\0get_eng_oilpres(int[8])\0"
    "get_eng_rev(int[8])\0getGPS(int[8])\0"
    "get_2111(int[8])\0"
};

void myWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myWidget *_t = static_cast<myWidget *>(_o);
        switch (_id) {
        case 0: _t->sendTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateTime(); break;
        case 2: _t->show_sys(); break;
        case 3: _t->hide_sys(); break;
        case 4: _t->close_sys(); break;
        case 5: _t->show_parameter(); break;
        case 6: _t->FeedDog(); break;
        case 7: _t->get_eng_ti_dis((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 8: _t->get_speed_data((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 9: _t->get_meter_distance((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 10: _t->get_motor_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 11: _t->get_unload_btn((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 12: _t->get_valve_state((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 13: _t->get_redischarge_machine((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 14: _t->get_clean_fan((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 15: _t->get_water_rate((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 16: _t->get_weight_dry((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 17: _t->get_elevator_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 18: _t->get_lose_rate((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 19: _t->get_gear_state((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 20: _t->get_throw_angle((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 21: _t->get_detect_value((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 22: _t->get_cut_width((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 23: _t->get_real_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 24: _t->get_cutter_freq((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 25: _t->get_feed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 26: _t->get_drum_speed((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 27: _t->get_eng_thm((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 28: _t->get_eng_oilpres((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 29: _t->get_eng_rev((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 30: _t->getGPS((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        case 31: _t->get_2111((*reinterpret_cast< int(*)[8]>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myWidget,
      qt_meta_data_myWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myWidget))
        return static_cast<void*>(const_cast< myWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int myWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void myWidget::sendTime(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
