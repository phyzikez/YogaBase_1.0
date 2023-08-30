#pragma once
#include <QWidget>
#include <QtWidgets>

// Represents Main Widget Contains All App's Features
class MainWidget : public QWidget
{
    Q_OBJECT
private:
    friend class AddAsanaWidget;
    // Contains All Tabs (Each Tab Represents Separate App's Feature)
    QTabWidget tabs;
    // Header Strings For Tabs
    QStringList tabsItems;
    // Tab Size
    QSize tabSize {100, 80};
    // Margin Values To Adjust Tab UI
    QMargins tabMargs {20,20,20,20};
    // Container Of Separate Feature Widgets
    QVector<QWidget*> widgets;
    // Current Language (0 Indicates ENG)
    bool curLang = 0;
public:
    // CTOR
    MainWidget(QWidget* table, QWidget* detail, QWidget* search, QWidget* add, bool isEng);
    // Container Of Language Descriptions
    std::array<QString, 2> langs = {"EN", "RU"};
    // Updates All Tabs In Real Time
    void updateTabs();
    // Updates Events Connected With Widgets After DB Updating
    void updateEventCards();
};
