#pragma once
#include <QtWidgets>
#include <array>
#include "datasaver.h"

// Friend Of Current Classes
class AsanaDetailWidget;

// Widget Represents Hex-Styled Asana's Benefit On Detail Asana's Page
class HexWidget : public QWidget {
    Q_OBJECT
    friend AsanaDetailWidget;
private:
    // Background Image Container For Hex
    QLabel *hexLblBack;
    // Benefit Image Container For Hex
    QLabel *optLblBack;
    // Benefit Source Image
    QPixmap *hexPic;
    // Adds Some Visual Adjustments (Shadow, Blur Effects)
    void setHexEffects(bool isActive);
public:
    // CTOR
    HexWidget(const QString& pathOptIcon, bool isActive);
};

// Widget Represents Navigation Arrow On Asana Page
class ArrowWidget : public QWidget {
    Q_OBJECT
    friend AsanaDetailWidget;
private:
    // Contains Arrow image
    QLabel *tempItem;
public:
    // CTOR (isRight Equals Right Arrow)
    ArrowWidget(bool isRight);
signals:
    // Activates Arrow Clicking To Navigate
    void mousePressEvent(QMouseEvent *event);
};

// Widget Represents Circle-Styled Asana Photo As A Part Of Navigation System
class CircleAsanaWidget : public QWidget {
    Q_OBJECT
    friend AsanaDetailWidget;
private:
    // Circle's Id
    int id;
    // Main Circle Layout
    QHBoxLayout *lt;
    // Asana's Png-Photo Path Placed In Circle
    QString picPath;
    // Asana's Photo Container
    QLabel* tempItem;
    // Asana's Photo
    QPixmap* picItem;
public:
    // CTOR (isActive With True-Value Indicates The Middle Circle)
    CircleAsanaWidget(bool isActive, int idx, QString path);
    // Circle's Path Photo Getter
    QString getCircPhotoPath() {
        return picPath;
    }
signals:
    // Activates Circle Click Action
    void mousePressEvent(QMouseEvent *event);
};

// Main Tab Widget Represents The Asana's Information Page
class AsanaDetailWidget : public QWidget {
    Q_OBJECT
    friend class MainWidget;
private:
    // Reference To DB
    const DataSaver& database;
    // Size-Fixed Circle Widgets
    std::array<CircleAsanaWidget*, 7> asanaCircles;
    // Container For All Asana Types Labels
    QList<QLabel*> types;
    // Page's Background Image Container
    QLabel* backWrapLabel = nullptr;
    // Background Image
    QPixmap* picBackAsana = nullptr;
    // Layouts Used To Contain Separated Elements
    QVBoxLayout *main = nullptr;
    QHBoxLayout *cols = nullptr;
    QVBoxLayout *innerLt = nullptr;
    QVBoxLayout *col1Lt = nullptr;
    QVBoxLayout *line1Lt = nullptr;
    QVBoxLayout *line2Lt = nullptr;
    QHBoxLayout *typesLt = nullptr;
    QVBoxLayout *line3Lt = nullptr;
    QVBoxLayout *line4Lt = nullptr;
    QVBoxLayout *carouselLt = nullptr;
    QHBoxLayout *itemslLt = nullptr;
    QVBoxLayout *col2Lt = nullptr;
    QVBoxLayout *altNameLt = nullptr;
    QVBoxLayout *nameLt = nullptr;
    // Widget Represents The Carousel-Styled Container Of Circles
    QWidget *carousel = nullptr;
    // Contains Detail Asana's Description
    // IN NEXT APP'S VERSION WILL CONTAIN MORE SEPARATED AND INHANCED INFORMATION
    QLabel *dynOptDesc = nullptr;
    // Contains Asana's Nuances
    QLabel *detailDesc = nullptr;
    // Asana's Main Photo Container
    QLabel *pix = nullptr;
    // Asana's Main Photo
    QPixmap* photoAsana = nullptr;
    // Asana's Transcripted Name
    QLabel *altName = nullptr;
    // Asana's Origin Name
    QLabel *name = nullptr;
    // Shadow Effects
    QGraphicsDropShadowEffect *shadowAName = nullptr;
    // Size-Fixed Array Of Hexes
    std::array<QWidget*, 5> hexWrapWids;
    // Size-Fixed Array Of Hexes' Layouts
    std::array<QHBoxLayout*, 5> hexLts ={nullptr, nullptr,nullptr,nullptr,nullptr};
    // Contains Hex-Widgets
    QVector<HexWidget*> hexWids;
    // Contains Hex Layout
    QWidget *hexWrapper = nullptr;
    // Navigation Left Arrow
    ArrowWidget* arrowL = nullptr;
    // Navigation Right Arrow
    ArrowWidget* arrowR = nullptr;
public:
    // CTOR (Gets A Reference To DB)
    AsanaDetailWidget(const DataSaver& db);
    // Updates Whole Widget
    void updateCircleWidget();
protected slots:
    // Activates Left Arrow On-Click Action
    void arrowLeftPressedAction(QMouseEvent*);
    // Activates Right Arrow On-Click Action
    void arrowRightPressedAction(QMouseEvent*);
    // Activates Asana's Circle Changing
    void rotateAsanaCircle(bool isForwardMove);
};
