#include "tableasanawidget.h"

TableAsanaWidget::TableAsanaWidget(const DataSaver& data) : data{data},
                                                            rows{data.getDimentions().first},
                                                            cols{data.getDimentions().second}
{
    this->setObjectName("TABLE_TAB");
    lt = new QVBoxLayout();

    table = nullptr;
    updateTableWidget();

    this->setLayout(lt);
};


void TableAsanaWidget::updateTableWidget() {
    // Clearing
    if (table) delete table;
    table = new QTableWidget();
    photoWid.hide();
    colsHeader.clear();
    rowsHeader.clear();

    QTableWidgetItem* cell = nullptr;
    auto &asanas = data.getAsanas();

    // Init Table Dimentions
    rows = data.getDimentions().first;
    cols = data.getDimentions().second;

    // Creating Table Body
    table->setRowCount(rows);
    table->setColumnCount(cols);
    for (int i=0; i<cols; i++){
        colsHeader << data.getHeaderOptions()[i].toUpper();
    }
    //qDebug() << table->rowCount() << " - " << table->columnCount();

    // Filling Table Content From Vector
    for (int i=0; i<rows; ++i){
        for (int j=0; j<cols; ++j){
            switch (j) {
            case 0 :
                cell = new QTableWidgetItem(QString("%1").arg(asanas[i].pic));
                cell->setForeground(QBrush(QColor(0,0,0,0)));
                cell->setToolTip(QObject::tr("<H1>Click To See Full Image</H1>"));
                photo = new QImage(DataSaver::PATH_PHOTO() + asanas[i].pic);
                *photo = photo->scaled(200, 50, Qt::KeepAspectRatioByExpanding);
                qbrush.setTextureImage(*photo);
                cell->setBackground(qbrush);
                break;
            case 1:
                cell = new QTableWidgetItem(QString("%1").arg(asanas[i].name));
                cell->setBackground(QBrush(QColor(40, 44, 48)));
                rowsHeader << asanas[i].name.toUpper();
                break;
            case 2:
                cell = new QTableWidgetItem(QString("%1").arg(asanas[i].altName));
                cell->setBackground(QBrush(QColor(50, 54, 58)));
                break;
            case 3:
                cell = new QTableWidgetItem(QString("%1").arg(asanas[i].posType));
                cell->setBackground(QBrush(QColor(60, 64, 68)));
                break;
            case 4:
                cell = new QTableWidgetItem(QString("%1").arg(asanas[i].desc));
                cell->setBackground(QBrush(QColor(70, 74, 78)));
                break;
            default:
                // bit unpack
                cell = new QTableWidgetItem(QString("%1").arg((asanas[i].options & (1 << (31-j+5))) ? "+" : "-"));
                QBrush cellBrush(cell->text() == "+" ? cellColorTrue : cellColorFalse, Qt::BrushStyle::SolidPattern);
                cell->setBackground(cellBrush);
                break;
            }
            cell->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, j, cell);
        }
    }

    // Adjusting Table
    table->setObjectName("TABLE");
    table->horizontalScrollBar()->setObjectName("H_BAR");
    table->verticalScrollBar()->setObjectName("V_BAR");

    // Acivate Sorting By Column
    table->setSortingEnabled(true);

    table->setMouseTracking(true);

    // Setting Headers
    hh = table->horizontalHeader();
    vv = table->verticalHeader();
    hh->setObjectName("HH");
    vv->setObjectName("VV");
    table->setVerticalHeaderLabels(rowsHeader);
    QTableWidgetItem *it = nullptr;
    for (int i=0, n = data.getOptFiles().size()+5; i<n; ++i) {
        it = new QTableWidgetItem();
        if (i>4) {
            it->setIcon(QIcon(QPixmap(data.getOptFiles()[i-5])));
        }
        it->setText(colsHeader.takeFirst());
        it->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        table->setHorizontalHeaderItem(i, it);
    }
    hh->hideSection(1); // hide dublicate name
    hh->moveSection(0,4); // move photo closer to opt

    updateNameColumn();

    lt->addWidget(table);
    lt->addWidget(&photoWid);

    // Setting Cursor Moves
    hh->installEventFilter(new MyFilter(hh));
    vv->installEventFilter(new MyFilter(vv));
    table->installEventFilter(new MyFilter(table));

    ////////////            EVENTS          ////////////
    // Update Main Column After Filtering
    QObject::connect(table->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(updateNameColumn()));
    // Open By Click Photo
    QObject::connect(table, SIGNAL(cellClicked(int, int)), this, SLOT(showAsanaPhoto(int, int)));
    // Close By Click Photo
    QObject::connect(&photoWid, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(closeAsanaPhoto(QMouseEvent*)));

    // Protect Table Changes From User's Input
    connect(table, &QTableWidget::itemSelectionChanged, [&]() {
        protectedText = table->currentItem()->text();
    });
    connect(table, &QTableWidget::cellChanged, [&]() {
        table->currentItem()->setText(protectedText);
    });
}
