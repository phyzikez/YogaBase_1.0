#include "asanadetailwidget.h"

HexWidget::HexWidget(const QString& pathOptIcon, bool isActive) {
    QHBoxLayout* main = new QHBoxLayout();
    // Hex Layer
    hexLblBack = new QLabel();
    hexLblBack->setObjectName("HEX_BACK_IMG");
    // Opt Layer
    optLblBack = new QLabel();
    optLblBack->setObjectName("HEX_OPT_IMG");

    hexPic = new QPixmap();
    setHexEffects(isActive);

    QPixmap *optPic = new QPixmap(pathOptIcon);
    *optPic = optPic->scaled(38, 38);
    optLblBack->setPixmap(*optPic);
    // Setting ToolTip
    auto pos1 = std::find(pathOptIcon.rbegin(), pathOptIcon.rend(), '_');
    auto pos2 = std::find(pathOptIcon.rbegin(), pathOptIcon.rend(), '.')+1;
    QString tip;
    std::for_each(pos2, pos1, [&tip](QChar ch){tip.push_front(ch);});
    tip.push_front("<H1>");
    tip.push_back("</H1>");
    // Required To Make Lang Switch Comparable
    this->setToolTip(tr(tip.toStdString().c_str()));
    this->setToolTipDuration(2000);
    this->setCursor(QCursor(Qt::WhatsThisCursor));

    // Combine layers
    QHBoxLayout* proxyLt = new QHBoxLayout();
    proxyLt->addWidget(optLblBack);
    hexLblBack->setLayout(proxyLt);
    main->addWidget(hexLblBack);
    this->setLayout(main);

}

void HexWidget::setHexEffects(bool isActive) {
    QString file;
    if (isActive) {
        QGraphicsDropShadowEffect *shadowHex = new QGraphicsDropShadowEffect();
        QGraphicsDropShadowEffect *shadowHexOpt = new QGraphicsDropShadowEffect();
        shadowHex->setBlurRadius(15);
        shadowHex->setColor(qRgba(238,174,51,170));
        shadowHex->setOffset(-3, 3);
        shadowHexOpt->setBlurRadius(2);
        shadowHexOpt->setColor(qRgba(35, 30, 40, 180));
        shadowHexOpt->setOffset(-1, 1);
        file = "_active.png";
        optLblBack->setGraphicsEffect(shadowHexOpt);
        hexLblBack->setGraphicsEffect(shadowHex);
    }
    else {
        file = ".png";
        hexLblBack->setGraphicsEffect(nullptr);
    }
    hexPic->load(":/helper/helper_icons/hex" + file);
    *hexPic = hexPic->scaled(56, 56);
    hexLblBack->setPixmap(*hexPic);
}

ArrowWidget::ArrowWidget(bool isRight) {
    tempItem = new QLabel();
    tempItem->setObjectName(isRight ? "CAROUSEL_ARROW_RIGHT" : "CAROUSEL_ARROW_LEFT");

    QGraphicsDropShadowEffect *shadowItem = new QGraphicsDropShadowEffect();
    shadowItem->setBlurRadius(10);
    shadowItem->setColor(qRgba(35, 30, 40, 140));
    shadowItem->setOffset(-2, 7);
    tempItem->setGraphicsEffect(shadowItem);
    this->setCursor(QCursor(Qt::PointingHandCursor));

    QHBoxLayout* lt = new QHBoxLayout();
    lt->addWidget(tempItem);
    this->setLayout(lt);

    // -------- EVENTS -------- //
}

CircleAsanaWidget::CircleAsanaWidget(bool isActive, int idx, QString path) : id{idx}, picPath{path} {
    tempItem = new QLabel("");

    QGraphicsDropShadowEffect *shadowItem = new QGraphicsDropShadowEffect();
    shadowItem->setBlurRadius(10);
    shadowItem->setColor(qRgba(35, 30, 40, 140));
    shadowItem->setOffset(-2, 7);
    tempItem->setGraphicsEffect(shadowItem);

    picPath.erase(picPath.cend()-4, picPath.cend());
    picPath.push_back("-removebg-preview.png");
    picPath.push_front(DataSaver::PATH_ALPHA());
    picItem = new QPixmap(picPath);

    if (isActive){
        tempItem->setObjectName("CAROUSEL_ITEM_ACTIVE");
        *picItem = picItem->scaled(160, 160);
    }
    else {
        tempItem->setObjectName("CAROUSEL_ITEM");
        *picItem = picItem->scaled(100, 100);
        this->setCursor(QCursor(Qt::PointingHandCursor));
    }
    tempItem->setPixmap(*picItem);

    lt = new QHBoxLayout();
    lt->addWidget(tempItem);
    this->setLayout(lt);
}

AsanaDetailWidget::AsanaDetailWidget(const DataSaver& db) : database{db}
{
    this->setObjectName("DETAIL_TAB");
    backWrapLabel = new QLabel();
    backWrapLabel->setObjectName("WRAPPER_BACKGROUND_TEXT");
    picBackAsana = new QPixmap();
    pix = new QLabel();
    pix->setObjectName("PIX");
    photoAsana = new QPixmap();
    dynOptDesc = new QLabel();
    dynOptDesc->setObjectName("DYN_OPT_DESC");
    detailDesc = new QLabel();
    detailDesc->setObjectName("DETAIL_DESC");
    altName = new QLabel();
    altName->setObjectName("A_ALT_NAME");
    name = new QLabel();
    name->setObjectName("A_NAME");
    carousel = new QWidget();
    carousel->setObjectName("CAROUSEL_WRAPPER");
    arrowL = new ArrowWidget(false);
    arrowL->setObjectName("CAROUSEL_ARROW_WID_LEFT");
    arrowR = new ArrowWidget(true);
    arrowR->setObjectName("CAROUSEL_ARROW_WID_RIGHT");
    QString tempPath;
    bool tempIsActive;
    int circleCount = asanaCircles.size(); // 7
    int asanaCount = database.getAsanas().size();
    int tempIdx = asanaCount-circleCount/2; // 3
    for (int i=0; i<circleCount; ++i) {
        if (i != circleCount/2) {
            tempIsActive = false;
        }
        else {
            tempIsActive = true;
            tempIdx = 0;
        }
        tempPath = database.getAsanas()[tempIdx].pic;
        asanaCircles[i] = new CircleAsanaWidget(tempIsActive, tempIdx, tempPath);
        tempIdx++;
    }
    updateCircleWidget();

    // ------------ EVENTS ------------ //
    // Arrow Button Click
    QObject::connect(arrowL, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(arrowLeftPressedAction(QMouseEvent*)));
    QObject::connect(arrowR, SIGNAL(mousePressEvent(QMouseEvent*)), this, SLOT(arrowRightPressedAction(QMouseEvent*)));
    // Circle Click
    for (int i=0, n=asanaCircles.size(); i<n; ++i) {
        if (i != n/2) {
            connect(asanaCircles[i], &CircleAsanaWidget::mousePressEvent, [=]() {
                for (int k=0; k<std::abs(i-n/2); k++) {
                    rotateAsanaCircle(i<n/2 ? false : true);
                }
            });
        }
    }
}

void AsanaDetailWidget::updateCircleWidget() {

    // Background (BACK)
    picBackAsana->load(DataSaver::PATH_PHOTO()+database.getAsanas()[0].pic);
    *picBackAsana = picBackAsana->scaledToWidth(1750);
    backWrapLabel->setPixmap(*picBackAsana);

    // Inner Block
    innerLt = new QVBoxLayout();
    // Column 1
    col1Lt = new QVBoxLayout();
    // Dynamic Opt Description
    line1Lt = new QVBoxLayout();
    QGraphicsDropShadowEffect *shadowDynOpt = new QGraphicsDropShadowEffect();
    shadowDynOpt->setColor(qRgb(35, 30, 40));
    shadowDynOpt->setOffset(0, 46);
    dynOptDesc->setGraphicsEffect(shadowDynOpt);
    // Upper Columns
    cols = new QHBoxLayout();
    cols->addLayout(col1Lt);
    dynOptDesc->setText("<SPAN>&#8853;</SPAN> "+database.getAsanas()[0].desc);
    dynOptDesc->setWordWrap(true);
    dynOptDesc->setAlignment(Qt::AlignJustify);
    line1Lt->addWidget(dynOptDesc);
    col1Lt->addLayout(line1Lt);
    innerLt->addLayout(cols);

    // Horizontal Asana Type List
    line2Lt = new QVBoxLayout();
    typesLt = new QHBoxLayout();
    QString curPos = "<CENTER>"+database.getAsanas()[0].posType+"</CENTER>";
    QString tempT;
    for (auto& t : database.getPoseTypeSet()) {
        types.push_back(new QLabel("<CENTER>"+t+"</CENTER>"));
        tempT = ("<CENTER>"+t+"</CENTER>" == curPos) ? "A_TYPE_ACTIVE" : "A_TYPE";
        types.back()->setObjectName(tempT);
        types.back()->setStyleSheet("QLabel#"+tempT);
        typesLt->addWidget(types.back());
    }
    tempT = (types.back()->text() == curPos) ? "A_TYPE_LAST_ACTIVE" : "A_TYPE_LAST";
    types.back()->setObjectName(tempT);
    types.back()->setStyleSheet("QLabel#"+tempT);
    line2Lt->addLayout(typesLt);
    col1Lt->addLayout(line2Lt);

    // Asana Detail Description
    line3Lt = new QVBoxLayout();
    QGraphicsDropShadowEffect *shadowDesc = new QGraphicsDropShadowEffect();
    shadowDesc->setBlurRadius(10);
    shadowDesc->setColor(qRgba(35, 30, 40, 140));
    shadowDesc->setOffset(-7, 7);
    detailDesc->setGraphicsEffect(shadowDesc);

    detailDesc->setText(database.getAsanas()[0].desc);
    detailDesc->setWordWrap(true);
    detailDesc->setAlignment(Qt::AlignJustify);
    line3Lt->addWidget(detailDesc);
    col1Lt->addLayout(line3Lt);

    // HEX

    line4Lt = new QVBoxLayout();
    if (hexWrapper == nullptr) hexWrapper = new QWidget();
    hexWrapper->setObjectName("HEX_WRAPPER");
    hexWrapper->setLayout(line4Lt);

    for (int i=0, n=hexWrapWids.size(); i<n; ++i) {
        hexWrapWids[i] = new QWidget();
        hexLts[i] = new QHBoxLayout();
        hexWrapWids[i]->setLayout(hexLts[i]);
        line4Lt->addWidget(hexWrapWids[i]);
    }
    hexWrapWids[0]->setObjectName("HEX_WRAPPER_LINE_7");
    hexWrapWids[1]->setObjectName("HEX_WRAPPER_LINE_9");
    hexWrapWids[2]->setObjectName("HEX_WRAPPER_LINE_7");
    hexWrapWids[3]->setObjectName("HEX_WRAPPER_LINE_5");
    hexWrapWids[4]->setObjectName("HEX_WRAPPER_LINE_4");

    QHBoxLayout *tempLt = nullptr;
    for (int i=0, n = database.getOptFiles().size(); i<n; ++i) {
        hexWids.push_back(new HexWidget(database.getOptFiles()[i],
                                        database.getAsanas()[0].options & (1 << (n-1-i)) ? true : false));
        hexWids.back()->setObjectName("HEX");
        if (i<7) {
            tempLt = hexLts[0];
        }
        else if (i>=7 && i <16){
            tempLt = hexLts[1];
        }
        else if (i>=16 && i <23){
            tempLt = hexLts[2];
        }
        else if (i>=23 && i <28){
            tempLt = hexLts[3];
        }
        else {
            tempLt = hexLts[4];
        }
        tempLt->addWidget(hexWids.back());
        tempLt->setSpacing(0);
    }
    col1Lt->addWidget(hexWrapper);

    // Line CAROUSEL
    carouselLt = new QVBoxLayout();
    itemslLt = new QHBoxLayout();
    itemslLt->addStretch(1);

    // Arrow Left
    itemslLt->addWidget(arrowL);

    // Asanas Circle Menu Item
    for (auto* circle : asanaCircles) {
        itemslLt->addWidget(circle);
    }

    // Arrow Right
    itemslLt->addWidget(arrowR);

    // Combine All Carousel Together
    if (carousel->children().empty()) carousel->setLayout(itemslLt);
    carouselLt->addWidget(carousel);
    innerLt->addLayout(carouselLt);

    // Column 2
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(10);
    shadow->setColor(qRgba(35, 30, 40, 140));
    shadow->setOffset(-7, 7);
    QVBoxLayout *col2Lt = new QVBoxLayout();
    cols->addLayout(col2Lt);

    // Photo
    photoAsana->load(DataSaver::PATH_PHOTO()+database.getAsanas()[0].pic);
    // Real Size
    uint w = photoAsana->width();
    uint h = photoAsana->height();
    *photoAsana = (w>h) ? photoAsana->scaledToWidth(750) : photoAsana->scaledToHeight(750);
    pix->setPixmap(*photoAsana);
    pix->setGraphicsEffect(shadow);
    col2Lt->addWidget(pix);

    // Line Asana Alt Name
    altNameLt = new QVBoxLayout();
    altName->setText("<CENTER>" + database.getAsanas()[0].altName + "</CENTER>");
    altNameLt->addWidget(altName);
    innerLt->addLayout(altNameLt);

    // Line Asana Name
    shadowAName = new QGraphicsDropShadowEffect();
    shadowAName->setColor(qRgb(35, 30, 40));
    shadowAName->setOffset(0, -10);
    nameLt = new QVBoxLayout();
    name->setText("<CENTER><SPAN>" + database.getAsanas()[0].name + "</SPAN></CENTER>");
    name->setGraphicsEffect(shadowAName);
    nameLt->addWidget(name);
    innerLt->addLayout(nameLt);

    // Set All Layers Together
    if (backWrapLabel->children().empty()) backWrapLabel->setLayout(innerLt);
    main = new QVBoxLayout();
    main->addWidget(backWrapLabel);
    if (this->children().empty()) this->setLayout(main);
}

void AsanaDetailWidget::arrowLeftPressedAction(QMouseEvent*) {
    rotateAsanaCircle(false);
}

void AsanaDetailWidget::arrowRightPressedAction(QMouseEvent*) {
    rotateAsanaCircle(true);
}

void AsanaDetailWidget::rotateAsanaCircle(bool isForward) {
    int nAsanas = database.getAsanas().size();

    // Update Carousel
    for (int i=0, n=asanaCircles.size(); i<n; ++i) {
        // Go forward
        if (isForward){
            asanaCircles[i]->id += (asanaCircles[i]->id != nAsanas-1) ? 1 : 1-nAsanas;
        }
        // Go back
        else {
            asanaCircles[i]->id += (asanaCircles[i]->id != 0) ? -1 : nAsanas-1;
        }
        // Update Circles
        asanaCircles[i]->picPath = database.getAsanas()[asanaCircles[i]->id].pic;
        asanaCircles[i]->picPath.erase(asanaCircles[i]->picPath.cend()-4, asanaCircles[i]->picPath.cend());
        asanaCircles[i]->picPath.push_back("-removebg-preview.png");
        asanaCircles[i]->picPath.push_front(DataSaver::PATH_ALPHA());
        asanaCircles[i]->picItem->load(asanaCircles[i]->picPath);
        if (i == n/2){
            asanaCircles[i]->tempItem->setObjectName("CAROUSEL_ITEM_ACTIVE");
            *asanaCircles[i]->picItem = asanaCircles[i]->picItem->scaled(160, 160);
        }
        else {
            asanaCircles[i]->tempItem->setObjectName("CAROUSEL_ITEM");
            *asanaCircles[i]->picItem = asanaCircles[i]->picItem->scaled(100, 100);
        }
        asanaCircles[i]->tempItem->setPixmap(*asanaCircles[i]->picItem);
    }

    // Get Current Asana Id
    int curId = asanaCircles[asanaCircles.size()/2]->id;

    // Update Names
    this->name->setText("<CENTER><SPAN>"+database.getAsanas()[curId].name+"</SPAN></CENTER>");
    this->altName->setText("<CENTER>"+database.getAsanas()[curId].altName+"</CENTER>");

    // Update Pics
    photoAsana->load(DataSaver::PATH_PHOTO() + database.getAsanas()[curId].pic);
    uint w = photoAsana->width();
    uint h = photoAsana->height();
    *photoAsana = (w>h) ? photoAsana->scaledToWidth(750) : photoAsana->scaledToHeight(750);
    pix->setPixmap(*photoAsana);

    picBackAsana->load(DataSaver::PATH_PHOTO() + database.getAsanas()[curId].pic);
    *picBackAsana = picBackAsana->scaledToWidth(1750);
    backWrapLabel->setPixmap(*picBackAsana);

    // Update Describe Texts
    this->detailDesc->setText(
        (database.getAsanas()[curId].desc == "-" || database.getAsanas()[curId].desc == "") ?
            tr("DETAIL DESCRIPTION IS ENABLE IN FULL VERSION OF APP...") :
            database.getAsanas()[curId].desc);
    // .... REQUIRED TO MAKE PARSE-PICKING (Future Options)
    this->dynOptDesc->setText(
        (database.getAsanas()[curId].desc == "-" || database.getAsanas()[curId].desc == "") ?
            tr("<SPAN>&#8853;</SPAN>ASANA OPTIONS IS ENABLE IN FULL VERSION OF APP...") :
            database.getAsanas()[curId].desc);

    // Update Asana Type
    QString curPos = "<CENTER>"+database.getAsanas()[curId].posType+"</CENTER>";
    QString tempT;
    for (auto* t : this->types) {
        tempT = (t->text() == curPos) ? "A_TYPE_ACTIVE" : "A_TYPE";
        t->setObjectName(tempT);
        t->setStyleSheet("QLabel#"+tempT);
    }
    tempT = (this->types.back()->text() == curPos) ? "A_TYPE_LAST_ACTIVE" : "A_TYPE_LAST";
    this->types.back()->setObjectName(tempT);
    this->types.back()->setStyleSheet("QLabel#"+tempT);

    // Update Hex
    for (int i=0, n = hexWids.size(); i<n; ++i) {
        hexWids[i]->setHexEffects(database.getAsanas()[curId].options & (1 << (n-1-i)));
    }
}
