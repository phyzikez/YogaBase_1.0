/****************************************************************************
** Meta object code from reading C++ file 'addasanawidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../YOGA3/addasanawidget.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addasanawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS = QtMocHelpers::stringData(
    "AddAsanaWidget",
    "resetForm",
    "",
    "chooseBasePhoto",
    "chooseAlphaPhoto",
    "createNewAsana"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[15];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[17];
    char stringdata5[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS_t qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "AddAsanaWidget"
        QT_MOC_LITERAL(15, 9),  // "resetForm"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 15),  // "chooseBasePhoto"
        QT_MOC_LITERAL(42, 16),  // "chooseAlphaPhoto"
        QT_MOC_LITERAL(59, 14)   // "createNewAsana"
    },
    "AddAsanaWidget",
    "resetForm",
    "",
    "chooseBasePhoto",
    "chooseAlphaPhoto",
    "createNewAsana"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAddAsanaWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x09,    1 /* Protected */,
       3,    0,   39,    2, 0x09,    2 /* Protected */,
       4,    0,   40,    2, 0x09,    3 /* Protected */,
       5,    0,   41,    2, 0x09,    4 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddAsanaWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAddAsanaWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddAsanaWidget, std::true_type>,
        // method 'resetForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chooseBasePhoto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chooseAlphaPhoto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createNewAsana'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddAsanaWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddAsanaWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resetForm(); break;
        case 1: _t->chooseBasePhoto(); break;
        case 2: _t->chooseAlphaPhoto(); break;
        case 3: _t->createNewAsana(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *AddAsanaWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddAsanaWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAddAsanaWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddAsanaWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
