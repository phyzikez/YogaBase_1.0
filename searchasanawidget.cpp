#include "searchasanawidget.h"

SearchAsanaWidget::SearchAsanaWidget(DataSaver& db, unsigned int cols) : database{db}, colCards{cols}
{
    this->setObjectName("SEARCH_TAB");
    form = new SearchForm();
    form->setObjectName("SEARCH_FORM");
    layoutCards = new QGridLayout();
    layoutCards->setAlignment(Qt::AlignCenter);
    // Layouts
    layout = new QHBoxLayout();
    for (int i=0, k=colCards; i<k; ++i) {
        layoutCards->setColumnMinimumWidth(i, 330);
    }

    // Search Form
    for (const QString &type : database.getPoseTypeSet()) {
        listPosTypes << type;
    }
    for (auto *el : form->children()) {
        //qDebug() << el->objectName();
        for (auto *ell : el->children()) {
            // checkboxes (opts)
            if (ell->objectName().contains("checkBox")) {
                boxes.push_back(reinterpret_cast<QCheckBox*>(const_cast<QObject*>(ell)));
            }
            // combobox (pose types)
            else if (ell->objectName().contains("comboBox")) {
                cmb = reinterpret_cast<QComboBox*>(const_cast<QObject*>(ell));
                cmb->addItem(tr("all types"));
                cmb->addItems(listPosTypes);
            }
        }
    }
    for (int i=0, s=boxes.count(); i<s; ++i){
        boxes[i]->setText(database.getHeaderOptions()[i+5]);
    }

    updateSearchWidget();

    // Setting Layouts
    scroll.setLayout(layoutCards);
    scroll.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll.horizontalScrollBar()->setObjectName("H_BAR");
    scroll.verticalScrollBar()->setObjectName("V_BAR");
    wrapWid = new QWidget();
    wrapWid->setObjectName("CARD_WRAPPER");
    wrapWid->setLayout(layoutCards);
    scroll.setWidget(wrapWid);
    scroll.setObjectName("SCROLL");
    QWidget *wrapperSearchWid = new QWidget();
    wrapperSearchWid->setObjectName("SEARCH_WRAPPER");
    QPixmap *decoPicUp = new QPixmap(":/helper/helper_icons/make.png");
    *decoPicUp = decoPicUp->scaledToWidth(412);
    QLabel* decoLineUpper = new QLabel();
    decoLineUpper->setObjectName("DECO_LINE_UPPER");
    decoLineUpper->setPixmap(*decoPicUp);
    decoLineUpper->setAlignment(Qt::AlignBottom);
    QPixmap *decoPicBtm = new QPixmap(":/helper/helper_icons/make.png");
    QLabel* decoLineBottom = new QLabel();
    decoLineBottom->setObjectName("DECO_LINE_BOTTOM");
    decoLineBottom->setPixmap(*decoPicBtm);
    decoLineBottom->setAlignment(Qt::AlignTop);
    wrapperSearchLt = new QVBoxLayout();
    wrapperSearchLt->addWidget(decoLineUpper);
    wrapperSearchLt->addWidget(form);
    wrapperSearchLt->addWidget(decoLineBottom);
    wrapperSearchWid->setLayout(wrapperSearchLt);
    layout->addWidget(wrapperSearchWid);
    layout->addWidget(&scroll);
    this->setLayout(layout);
}

void SearchAsanaWidget::updateSearchWidget(){

    // Clearing Old Data
    searchClearButPress(); // ! NEED MOVE To The End
    cardList.clear();
    unsigned int rows=database.getAsanas().size()/colCards + bool(database.getAsanas().size()%colCards);
    for (unsigned int i=0; i<rows; ++i) {
        for (unsigned int j=0; j<colCards; ++j) {
            if (layoutCards->itemAtPosition(i, j) != nullptr) {
                layoutCards->removeWidget(layoutCards->itemAtPosition(i, j)->widget());
            }
        }
    }

    // Cards
    int N = database.getAsanas().size();
    QVector<int> *v = new QVector<int>(N);
    std::generate_n(v->begin(), N, [i=0]() mutable {
        return i++;
    });

    initCards(*v);

    unsigned int r=database.getAsanas().size()/colCards + bool(database.getAsanas().size()%colCards);
    for (unsigned int i=0; i<r; ++i) {
        for (unsigned int j=0; j<colCards; ++j) {
            if (colCards*i+j < cardList.size()) {
                cardList[colCards*i+j]->coords = {i, j};
                cardList[colCards*i+j]->isRequired = true;
                layoutCards->addWidget(cardList[colCards*i+j], i, j);
            }
        }
        layoutCards->setRowMinimumHeight(i, 550);
    }

    // -------- EVENTS ---------- //
    // Buttons From UI
    QPushButton *findBut = form->findChild<QPushButton*>("BUT_S");
    QPushButton *clearBut = form->findChild<QPushButton*>("BUT_CLEAR");
    QObject::connect(findBut, SIGNAL(clicked(bool)), this, SLOT(searchUpdateButPress()));
    QObject::connect(clearBut, SIGNAL(clicked(bool)), this, SLOT(searchClearButPress()));
}

void SearchAsanaWidget::initCards(QVector<int>& idx){

    CardWidget *pCard = nullptr;
    QString tempName, tempAltName;
    for (auto& id : idx) {
        // If Too Long Names -> Use ...
        tempName = database.getAsanas()[id].name;
        if (tempName.size() > 13) {
            tempName.erase(tempName.cbegin()+13, tempName.cend());
            tempName += "...";
        }
        tempAltName = database.getAsanas()[id].altName;
        if (tempAltName.size() > 24) {
            tempAltName.erase(tempAltName.cbegin()+24, tempAltName.cend());
            tempAltName += "...";
        }
        // Upgrade Path To "Circle"-Version
        QString updPath = database.getAsanas()[id].pic;
        updPath.erase(updPath.cend()-4, updPath.cend());
        updPath.push_back("-removebg-preview.png");
        updPath.push_front(DataSaver::PATH_ALPHA());
        // Creating New Card
        pCard = new CardWidget(updPath,
                               tempName,
                               tempAltName,
                               database.getAsanas()[id].posType,
                               database.getAsanas()[id].options);
        pCard->picPath = updPath;
        // Opt Assign
        pCard->opts = database.getAsanas()[id].options;
        // Descr
        pCard->descr = database.getAsanas()[id].desc;

        // Collecting Cards
        cardList.push_back(pCard);
    }
}

void SearchAsanaWidget::searchClearButPress() {
    // Reset UI
    QComboBox* cb =  this->form->findChild<QComboBox*>("comboBox");
    cb->setCurrentIndex(0);
    QTextEdit* te = this->form->findChild<QTextEdit*>("TEX_EDIT");
    te->setText("");
    for (auto *box : boxes) {
        box->setCheckState(Qt::CheckState::Unchecked);
    }

    // Reset All Cards To Required
    unsigned int rows=database.getAsanas().size()/colCards + bool(database.getAsanas().size()%colCards);
    for (unsigned int i=0; i<rows; ++i) {
        for (unsigned int j=0; j<colCards; ++j) {
            if (layoutCards->itemAtPosition(i, j) != nullptr) {
                static_cast<CardWidget*>(layoutCards->itemAtPosition(i, j)->widget())->isRequired = false;
                static_cast<CardWidget*>(layoutCards->itemAtPosition(i, j)->widget())->hide();
            }
        }
    }
}

void SearchAsanaWidget::searchUpdateButPress() {
    // Final Result Check State
    bool isCardRequired = true;

    // Get Current Options Mask Search Filter
    unsigned int maskOpts = 0;
    for (unsigned int i=0, count = boxes.size(); i<count; ++i) {
        if (boxes[i]->isChecked()){
            maskOpts |= (1 << (count-1-i));
        }
    }

    // Get Type Asana Info
    QString pickedType = cmb->itemText(cmb->currentIndex());

    // Get User Typed Asana Description Text
    QString text = form->findChild<QTextEdit*>("TEX_EDIT")->toPlainText();
    // DecrText Filter (By Separate Word)
    QStringList descWords = text.split(" ");
    //qDebug() << descWords;

    // Filter
    CardWidget* card = nullptr;
    unsigned int rows=database.getAsanas().size()/colCards + bool(database.getAsanas().size()%colCards);
    for (unsigned int i=0; i<rows; ++i) {
        for (unsigned int j=0; j<colCards; ++j) {
            if (layoutCards->itemAtPosition(i, j) != nullptr) {
                card = dynamic_cast<CardWidget*>(layoutCards->itemAtPosition(i, j)->widget());
                // ReNew Filter
                isCardRequired = true;

                // ----------- OPTS FILTER ----------- //
                if ((card->opts & maskOpts) != maskOpts) {
                    isCardRequired = false;   ///// -
                }

                // ---------- POSETYPE FILTER -------- //
                if (pickedType != cmb->itemText(0) && pickedType != card->poseType.text()){
                    isCardRequired = false; ///// -
                }

                // ----------- TEXT FILTER ---------- //
                if (text != "") {
                    // Search In Name
                    auto iterName = std::find_if(descWords.begin(), descWords.end(), [&](QString& word){
                        return card->name.text().contains(word, Qt::CaseInsensitive);
                    });
                    // Search In AltName
                    auto iterAltName = std::find_if(descWords.begin(), descWords.end(), [&](QString& word){
                        return card->altName.text().contains(word, Qt::CaseInsensitive);
                    });
                    // Search In Desc
                    auto iterDescr = std::find_if(descWords.begin(), descWords.end(), [&](QString& word){
                        return card->descr.contains(word, Qt::CaseInsensitive);
                    });
                    // Final Desc Check
                    if (iterName == descWords.end() && iterAltName == descWords.end() && iterDescr == descWords.end()) {
                        isCardRequired = false; ///// -
                    }
                }

                // ---------- FINAL FILTER ----------- //
                card->isRequired = isCardRequired ? true : false;
                isCardRequired ? card->show() : card->hide();
            }
        }
    }
    // Redraw UI
    updateLayout();
}

void SearchAsanaWidget::updateLayout() {
    // Pos
    int goodX, goodY, badX, badY;

    // ReAccumulate Cards
    QVector<QLayoutItem*> vec;
    unsigned int rows=database.getAsanas().size()/colCards + bool(database.getAsanas().size()%colCards);
    for (unsigned int i=0; i<rows; ++i) {
        for (unsigned int j=0; j<colCards; ++j) {
            if (layoutCards->itemAtPosition(i, j) != nullptr) {
                vec.push_back(layoutCards->itemAtPosition(i, j));
            }
        }
    }

    // Required Card Init Position
    QVector<QLayoutItem*>::iterator good = vec.begin();
    // Not Required Card Init Position
    QVector<QLayoutItem*>::iterator bad = vec.begin();

    while (true) {

        // Finding Not/Required Card Position To Swap
        good = std::find_if(good, vec.end(), [](QLayoutItem* card){
            return static_cast<CardWidget*>(card->widget())->isRequired;
        });
        bad = std::find_if(bad, vec.end(), [](QLayoutItem* card){
            return !static_cast<CardWidget*>(card->widget())->isRequired;
        });

        // End Search
        if (good == vec.end() || bad == vec.end()) {
            break;
        }

        // Founded Pos
        goodX = static_cast<CardWidget*>((*good)->widget())->coords.first;
        goodY = static_cast<CardWidget*>((*good)->widget())->coords.second;
        badX = static_cast<CardWidget*>((*bad)->widget())->coords.first;
        badY = static_cast<CardWidget*>((*bad)->widget())->coords.second;

        // Swap Condition
        if ((goodX > badX) || (goodX <= badX && goodY > badY)) {
            // Swap Widgets Into Layout
            auto badItem = layoutCards->itemAtPosition(badX, badY);
            auto goodItem = layoutCards->itemAtPosition(goodX, goodY);
            layoutCards->removeItem(badItem);
            layoutCards->removeItem(goodItem);
            static_cast<CardWidget*>(badItem->widget())->coords = {goodX, goodY};
            static_cast<CardWidget*>(goodItem->widget())->coords = {badX, badY};
            layoutCards->addItem(badItem, goodX, goodY);
            layoutCards->addItem(goodItem, badX, badY);

            // Change Iters For Next Search
            *good = *bad;
            // Go To Next Not Required Pos
            bad++;
        }
        // Definitely Go To Next Not Required Pos
        good++;
    }

}
