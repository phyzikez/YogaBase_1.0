#include "mainwidget.h"
#include "tableasanawidget.h"
#include "searchasanawidget.h"
#include "asanadetailwidget.h"

MainWidget::MainWidget(QWidget* table, QWidget* detail, QWidget* search, QWidget* add, bool isEng)
{
    this->setObjectName("MAIN_WIDGET");
    this->setWindowTitle("YogaBase 1.0");

    tabsItems << tr("TABLE\nASANA") << tr("DETAIL\nASANA") << tr("SEARCH\nASANA") << tr("CREATE\nASANA");

    QVBoxLayout *lt = new QVBoxLayout();
    lt->addWidget(&tabs);
    this->setLayout(lt);

    // TAB 1 (ASANA TABLE)
    widgets.push_back(table);
    tabs.addTab(widgets[0], QPixmap(":/tab/tab_icons/table_tab.png"), tabsItems[0]);
    // TAB 2 (ASANA DETAIL)
    widgets.push_back(detail);
    tabs.addTab(widgets[1], QPixmap(":/tab/tab_icons/detail_tab.png"), tabsItems[1]);
    // TAB 3 (ASANA SEARCH)
    widgets.push_back(search);
    tabs.addTab(widgets[2], QPixmap(":/tab/tab_icons/search_tab.png"), tabsItems[2]);
    // TAB 4 (ASANA ADD NEW)
    widgets.push_back(add);
    tabs.addTab(widgets[3], QPixmap(":/tab/tab_icons/add_tab.png"), tabsItems[3]);

    // Additional Empty Tab For Lang Indicator
    QWidget *empty = new QWidget();
    tabs.addTab(empty, langs[isEng]);
    tabs.setTabEnabled(4, false);

    // SETTING APP STYLE
    tabs.setObjectName("TABS");
    tabs.tabBar()->setCursor(QCursor(Qt::PointingHandCursor));
    tabs.setContentsMargins(tabMargs);
    tabs.setIconSize(tabSize);
    this->resize(1830, 950);

    // Set Side Tabs
    tabs.setTabPosition(QTabWidget::West);
    updateEventCards();
}

void MainWidget::updateEventCards() {
    // ------------- EVENTS ------------ //
    // Asana Card Detail Button Clicked -> Go To Clicked Asana Detail Page
    for (CardWidget* card : dynamic_cast<SearchAsanaWidget*>(tabs.widget(2))->cardList) {
        connect(card->getDetailButton(), &QPushButton::clicked, [=](){
            // Wait Indicator
            QProgressDialog* pd = new QProgressDialog(tr("Moving To Asana..."), "&OK", 0, 100000000);
            pd->setWindowTitle(tr("One Moment..."));
            pd->setMinimumDuration(0);
            pd->setValue(0);
            pd->open();
            QString pathToFind = card->getPhotoPath();
            AsanaDetailWidget* det = dynamic_cast<AsanaDetailWidget*>(tabs.widget(1));
            while (det->asanaCircles[3]->getCircPhotoPath() != pathToFind) {
                // ...Better Use More Faster Non-UI-Method (no need for pd)
                det->rotateAsanaCircle(true);
            }
            pd->close();
            tabs.setCurrentIndex(1);
        });
    }
}

void MainWidget::updateTabs() {
    dynamic_cast<TableAsanaWidget*>(tabs.widget(0))->updateTableWidget();
    dynamic_cast<AsanaDetailWidget*>(tabs.widget(1))->updateCircleWidget();
    dynamic_cast<SearchAsanaWidget*>(tabs.widget(2))->updateSearchWidget();
    updateEventCards();
}
