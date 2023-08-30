#include "cardwidget.h"

CardWidget::CardWidget(const QString& photoPath, const QString &name, const QString &altName,
                       const QString &poseType, unsigned int numOpts)
{
    this->setObjectName("CARD_WIDGET");
    this->setMinimumHeight(545);
    this->setMaximumHeight(545);
    this->setMinimumWidth(330);
    this->setMaximumWidth(330);

    // Card Layout
    QVBoxLayout *clt = new QVBoxLayout();

    // Asana Photo
    this->picPath = photoPath;
    this->photo = new QPixmap(photoPath);
    //qDebug() << this->photo->size();
    *this->photo = this->photo->scaledToHeight(300);
    *this->photo = this->photo->scaledToWidth(300);
    this->pix = new QLabel();
    this->pix->setObjectName("ASANA_PHOTO"); // CSS-NAME
    this->pix->setPixmap(*photo);

    this->pix->setMinimumWidth(400);
    this->pix->setMinimumHeight(400);
    this->pix->setMaximumWidth(400);
    this->pix->setMaximumHeight(400);

    this->opts = 0;

    clt->addWidget(this->pix);

    // Asana Name
    this->name.setText(tr(name.toStdString().c_str()));
    this->name.setObjectName("ASANA_NAME"); // CSS-NAME
    clt->addWidget(&this->name);

    // Asana AltName
    this->altName.setText(altName);
    this->altName.setObjectName("ASANA_ALTNAME"); // CSS-NAME
    clt->addWidget(&this->altName);

    // Asana Type
    this->poseType.setText(poseType);
    this->poseType.setObjectName("ASANA_POSETYPE"); // CSS-NAME
    clt->addWidget(&this->poseType);

    // Asana Option Count (In HexPic)
    // Count 1-bits (replace to std::bitop)
    int tempCount = 0;
    do {
        if (numOpts%2) tempCount++;
    } while (numOpts /= 2);
    this->numOpts.setText(QString::number(tempCount));
    this->numOpts.setObjectName((tempCount < 10) ? "ASANA_OPTIONCOUNT_9" : "ASANA_OPTIONCOUNT_10"); // CSS-NAME
    clt->addWidget(&this->numOpts);

    // Asana Button Detail
    this->butlt = new QHBoxLayout();

    this->butwid = new QWidget();
    this->butwid->setObjectName("ASANA_BUTTON_DETAIL_WIDGET"); // CSS-NAME
    this->butwid->setLayout(this->butlt);

    this->detailbuttonLeftText = new QLabel();
    this->detailbuttonLeftText->setText(tr("Go To Asana:"));
    this->detailbuttonLeftText->setObjectName("ASANA_BUTTON_DETAIL_TEXT_LEFT"); // CSS-NAME

    this->detailButton = new QPushButton(tr("Details"));
    this->detailButton->setObjectName("ASANA_BUTTON_DETAIL"); // CSS-NAME

    this->butlt->addWidget(this->detailbuttonLeftText);
    this->butlt->addWidget(this->detailButton);

    this->detailButton->setCursor(QCursor(Qt::PointingHandCursor));

    clt->addWidget(butwid);
    this->setLayout(clt);
}

QString CardWidget::getPhotoPath(){
    return picPath;
}

QPushButton* CardWidget::getDetailButton(){
    return detailButton;
}
