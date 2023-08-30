#pragma once
#include <QWidget>
#include <QtWidgets>
#include <array>
#include "datasaver.h"
#include "createform.h"
#include "mainwidget.h"

// Used To Create New Asana
class AddAsanaWidget : public QWidget {
    Q_OBJECT
    // Reference To DB
    DataSaver& database;
    // fixed array of asana's potentials
    std::array<QCheckBox, 32> opts;
    // UI Creation Form
    CreateForm* form;
    // Asana Pictures Open File Dialog
    QFileDialog *fileDialog;
    // Drop-List Of Asana's Position Type
    QComboBox *combo;
    // Contains Main Asana's Photo Path
    QLabel *lblPhoto;
    // Contains Additional Asana's Photo Path (.PNG)
    QLabel *lblPhotoAlpha;
    // Input Asana's Origin Name (Hindi)
    QTextEdit *nameEdit;
    // Input Asana's Transcript Name
    QTextEdit *altNameEdit;
    // Input Asana's Detail Description
    QTextEdit *descrEdit;
    // Input Asana's Options Array
    QVector<QCheckBox*> boxes;
    // Main Asana's Photo Path String
    QString fullPathMainPhoto;
    // Additional Asana's Photo Path String
    QString fullPathAlphaPhoto;
    // Edited Path Of Asana's Photo
    QString newFileName;
public:
    // CTOR (get info from DB)
    AddAsanaWidget(DataSaver& database);
protected slots:
    // Clear UI-Form
    void resetForm();
    // Choosing Asana'os Base Photo
    void chooseBasePhoto();
    // Choosing Asana'os Additional Photo
    void chooseAlphaPhoto();
    // Base Method To Add New Asana
    void createNewAsana();
};
