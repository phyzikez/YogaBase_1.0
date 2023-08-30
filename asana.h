#pragma once
#include <QWidget>

// Object Presentation of Asana
// Contains All Needed Parts
struct Asana{
    // Photo Of Asana
    QString pic;
    // Asana's Hindi Name
    QString name;
    // Asana's Transcripted Name
    QString altName;
    // Asana's Pose Type
    QString posType;
    // Asana's Detail Description
    QString desc;
    // Bitset Of Asana Benefits
    // Each Option Is Presented As A Single Bit
    unsigned int options;
    // CTOR default
    Asana() : Asana("", "", "", "", "") {}
    // CTOR Parametrized
    Asana(QString pic, QString name, QString altName, QString posType, QString desc) :
        pic{pic}, name{name}, altName{altName}, posType{posType}, desc{desc}, options{0} {}
};
