#pragma once
#include <QObject>
#include <QtWidgets>
#include <QWidget>
#include <QColor>
#include "datasaver.h"

// Represent Full-Image Asana's Photo Activated By Click
class PhotoWidget : public QWidget {
    Q_OBJECT
public:
    // Main Photo Layout
    QHBoxLayout* lt;
    // Contains Asana's Activated Photo
    QLabel *photoLbl;
    // Asana's Activated Photo
    QPixmap* pix;
    // Asana's Activated Photo Path
    QString path;
    // CTOR
    PhotoWidget() {
        photoLbl = new QLabel();
        lt = new QHBoxLayout();
        lt->addWidget(photoLbl);
        this->setLayout(lt);
        this->setObjectName("PHOTO_WID");
    }
    // Setting Active Photo
    void operator()(const QString& newPath) {
        pix = new QPixmap(newPath);
        *pix = pix->scaled(1600, 800, Qt::AspectRatioMode::KeepAspectRatio);
        photoLbl->setPixmap(*pix);
    }
signals:
    // Activates Click By Picked Photo
    void mousePressEvent(QMouseEvent *event);
};

// Represents Table-Styled Tab Showes Full Information About All Asanas
class TableAsanaWidget : public QWidget
{
    Q_OBJECT
private:
    // Reference To DB
    const DataSaver& data;
    // Reference To Count Of Asanas And Their Benefits
    int &rows;
    int &cols;
    // Used Layouts
    QVBoxLayout *lt;
    QHeaderView* hh;
    QHeaderView* vv;
    // Main Table Widget
    QTableWidget *table;
    // Widget For Activated Photo
    PhotoWidget photoWid;
    // Main Column And Row Texts
    QStringList colsHeader;
    QStringList rowsHeader;
    // Styling Widget
    QBrush qbrush;
    // Asana's Activated Photo
    QImage *photo = nullptr;
    // Colors Used To Indicate In-/Valid Asana's Benefit
    QColor cellColorTrue = qRgb(234,170,45); // +
    QColor cellColorFalse = qRgb(41,43,45);  // -
    // Savin String Used To Protect Of Changing Table Cells
    QString protectedText;
public:
    // CTOR
    TableAsanaWidget(const DataSaver& data);
    // Updates Table
    void updateTableWidget();
public slots:
    // Updates Main Name Header Column After Sorting By Custom Column
    void updateNameColumn() {
        QStringList updList;
        int n = table->verticalHeader()->count();
        for (int i=0; i<n; ++i) {
            updList << table->item(i,1)->text().toUpper();
        }
        table->setVerticalHeaderLabels(updList);
    }
    // Opens Full-Image Asana Photo By Click
    void showAsanaPhoto(int row, int col) {
        if (col == 0) {
            QString path = this->table->item(row, col)->text();
            this->photoWid(DataSaver::PATH_PHOTO() + path);
            int W = photoWid.parentWidget()->size().width();
            int w = photoWid.pix->width();
            table->hide();
            photoWid.show();
            photoWid.move((W-w)/2, 0);
            this->setCursor(Qt::PointingHandCursor);
        }
    }
    // Closes Full-Image Asana Photo By Click
    void closeAsanaPhoto(QMouseEvent* e) {
        if (e->type() == QEvent::MouseButtonPress){
            photoWid.move(0, 0);
            photoWid.hide();
            table->show();
            this->setCursor(Qt::ArrowCursor);
        }
    }
};

// Event-Filters For Specific Table Mouse Events
class MyFilter : public QObject {
public:
    MyFilter(QObject* obj = 0) : QObject(obj) {}
protected:
    bool eventFilter(QObject* o, QEvent* e) {
        if (e->type() == QEvent::Enter) {
            if (o->objectName() == "HH") {
                static_cast<QWidget*>(o->parent())->setCursor(Qt::UpArrowCursor);
            }
            else if (o->objectName() == "VV") {
                static_cast<QWidget*>(o->parent())->setCursor(Qt::PointingHandCursor);
            }
            return true;
        }
        if (e->type() == QEvent::Leave) {
            static_cast<QWidget*>(o->parent())->setCursor(Qt::ArrowCursor);
            return true;
        }
        return false;
    }
};
