#pragma once
#include <QWidget>
#include <QtWidgets>
#include <QDialog>
#include <QXmlStreamReader>
#include <array>
#include "asana.h"

// Represents The DataBase Contains Whole Information About Asana's
class DataSaver : public QObject
{
    Q_OBJECT
private:
    friend class AddAsanaWidget;
    // Container Of Predefined Asana's Benefits
    QVector<QString> headerOption = {
        tr("photo"), tr("name"), tr("altname"), tr("posetype"), tr("description"),
        tr("eyes"), tr("lungs"), tr("liver"), tr("stomach"), tr("spleen"), tr("intestine"), tr("kidney"),
        tr("hands"), tr("arms"), tr("legs"), tr("knees"), tr("neck"), tr("breast"), tr("press"), tr("spine"), tr("pelvic"),
        tr("intellect"), tr("neuro"), tr("posture"), tr("vestibular"), tr("cardio"), tr("urinary"), tr("sexual"),
        tr("endurance"), tr("anger"), tr("tiredness"), tr("stress"), tr("toxins"),
        tr("scoliosis"), tr("flatfoot"), tr("gout"), tr("tonsillitus")
    };
    // Container Of Predefined Asana's Benefit Image Pathes
    std::array<QString, 32> optFiles {
        ":/option/option_icons/organ_eye.png",
        ":/option/option_icons/organ_lungs.png",
        ":/option/option_icons/organ_liver.png",
        ":/option/option_icons/organ_stomach.png",
        ":/option/option_icons/organ_spleen.png",
        ":/option/option_icons/organ_intestine.png",
        ":/option/option_icons/organ_kidneys.png",
        ":/option/option_icons/body_hand.png",
        ":/option/option_icons/body_arm.png",
        ":/option/option_icons/body_leg.png",
        ":/option/option_icons/body_knee.png",
        ":/option/option_icons/body_neck.png",
        ":/option/option_icons/body_breast.png",
        ":/option/option_icons/body_press.png",
        ":/option/option_icons/body_vertebral.png",
        ":/option/option_icons/body_pelvic.png",
        ":/option/option_icons/system_intellect.png",
        ":/option/option_icons/system_neuro.png",
        ":/option/option_icons/system_stature.png",
        ":/option/option_icons/system_ballance.png",
        ":/option/option_icons/system_blood.png",
        ":/option/option_icons/system_urina.png",
        ":/option/option_icons/system_sexual.png",
        ":/option/option_icons/state_endurance.png",
        ":/option/option_icons/state_angry.png",
        ":/option/option_icons/state_tired.png",
        ":/option/option_icons/state_stress.png",
        ":/option/option_icons/state_toxins.png",
        ":/option/option_icons/disease_scoliosis.png",
        ":/option/option_icons/disease_flatfoot.png",
        ":/option/option_icons/disease_gout.png",
        ":/option/option_icons/disease_tonsillitis.png"
    };
    // Asanas' Base Photo Path
    static QString pathPhoto;
    // Asanas' Png Photo Path
    static QString pathAlpha;
    // Asanas' XML-DB path
    static QString path;
    // Set Of Unique Asana's Possible Position Types
    QSet<QString> poseTypeSet;
    // Main Container Of Asana's Information
    mutable QVector<Asana> asanas;
    // Asana's Count
    mutable int rows = 0;
    // Asana Benefit's Count
    mutable int cols = 0;
    // Contains Error State
    bool isError = false;
public:
    // CTOR (false-Value Indicates ENG-Version Of APP)
    // IN NEXT VERSION WILL REPLACED WITH SHORT-TYPE TO
    // SUPPORT MORE LANGUAGES
    DataSaver(bool lang);
    // Updates DB
    void updateDB();
    // DB-Getters For App's Tabs
    const QVector<Asana>& getAsanas() const;
    const QVector<QString>& getHeaderOptions() const;
    const QSet<QString>& getPoseTypeSet() const;
    const std::pair<int&, int&> getDimentions() const;
    const std::array<QString, 32>& getOptFiles() const;
    // Static-Getter For App's Main Photo Path
    static const QString PATH_PHOTO() {
        return pathPhoto;
    };
    // Static-Getter For App's Png-Photo Path
    static const QString PATH_ALPHA() {
        return pathAlpha;
    };
    // Static-Getter For App's Main Xml-File Path
    static const QString PATH_DB() {
        return path;
    };
    // Checks If Error Occures
    bool error() const {
        return isError;
    }
};
