#pragma once
#include <QtWidgets>
#include <algorithm>
#include <numeric>
#include "searchform.h"
#include "datasaver.h"
#include "cardwidget.h"

// Represents User's Tab For Searching Required Asana
class SearchAsanaWidget : public QWidget
{
    Q_OBJECT
private:
    friend class MainWidget;
    // Reference To DB
    const DataSaver& database;
    // Search Form
    SearchForm *form;
    // Grid Layout Contains Cards Of Asanas
    QGridLayout *layoutCards;
    // Helper Intermedite Layouts
    QHBoxLayout *layout;
    QVBoxLayout *wrapperSearchLt;
    QWidget *wrapWid;
    // Scroll Area For Cards' Table
    QScrollArea scroll;
    // Asana's Position Types String List Used In DropDown List
    QStringList listPosTypes;
    // DropDown List Of Asana's Position Types
    QComboBox* cmb;
    // Contains All Required Asanas' Cards
    QVector<CardWidget*> cardList;
    // CheckBoxes Used By User To Set Required Asana's Benefits
    QVector<QCheckBox*> boxes;
    // Count Of Grid Column
    unsigned int colCards;
public:
    // CTOR
    SearchAsanaWidget(DataSaver& database, unsigned int cols);
    // Initializes Asana's Cards
    void initCards(QVector<int>& idx);
    // Updates Main Layout
    void updateLayout();
    // Updates Searching Information
    void updateSearchWidget();
public slots:
    // Reacts To Search Button Click -> Searches Required Cards
    void searchUpdateButPress();
    // Reacts To Clear Button Click -> Clears Result Of Searching
    void searchClearButPress();
};
