#pragma once
#include <QtWidgets>

// Used As A Friend Class
class SearchAsanaWidget;

// Widget Represents A Separate Base Card-Styled Asana's Information
class CardWidget : public QWidget {
    //Q_OBJECT
    friend class SearchAsanaWidget;
private:
    // Used As A Container Of Asana's Benefits
    // Each Bit Is A Separate Benefit
    unsigned int opts;
    // Used For Searching System (true-Value Means Required Card)
    bool isRequired;
    // Card's Coordinates In Card Table
    std::pair<int, int> coords;
    // Asana's Description
    QString descr;
    // Asana's Photo
    QPixmap *photo = nullptr;
    // Asana's Photo Path
    QString picPath;
    // Asana's Origin Name
    QLabel name;
    // Asana's Transcripted Name
    QLabel altName;
    // Asana's Position Type Container
    QLabel poseType;
    // Contains A Count Of Asana's Benefits
    QLabel numOpts;
    // Container Of Asana's Photo
    QLabel *pix = nullptr;
    // Navigation Button Layout
    QHBoxLayout *butlt;
    // Navigation Button Widget
    QWidget *butwid;
    // Navigation Button
    QPushButton *detailButton;
    // Additional UI-Text
    QLabel* detailbuttonLeftText;
public:
    // CTOR
    CardWidget(const QString& photoPath, const QString &name, const QString &altName,
               const QString &poseType, unsigned int numOpts);
    // Button Getter
    QPushButton* getDetailButton();
    // Photo's Path Getter
    QString getPhotoPath();
};
