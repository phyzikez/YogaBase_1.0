/********************************************************************************
** Form generated from reading UI file 'createform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEFORM_H
#define UI_CREATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateForm
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *COMBO;
    QLabel *LBL_AKW;
    QPushButton *BUT_CREATE;
    QLabel *LBL_AT;
    QTextEdit *TEX_DESCR;
    QLabel *LBL_NAME;
    QLabel *LBL_ALT_NAME;
    QTextEdit *TEX_NAME;
    QTextEdit *TEX_ALT_NAME;
    QLabel *LBL_GOAL;
    QPushButton *BUT_RESET;
    QLabel *LBL_BS;
    QLabel *LBL_AB;
    QWidget *horizontalLayoutWidget_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_21;
    QCheckBox *checkBox_20;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_17;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_15;
    QLabel *LBL_D;
    QWidget *horizontalLayoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_37;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_36;
    QWidget *horizontalLayoutWidget_6;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_26;
    QCheckBox *checkBox_25;
    QCheckBox *checkBox_24;
    QCheckBox *checkBox_23;
    QCheckBox *checkBox_22;
    QWidget *horizontalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox;
    QWidget *horizontalLayoutWidget_7;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBox_32;
    QCheckBox *checkBox_31;
    QCheckBox *checkBox_30;
    QCheckBox *checkBox_29;
    QLabel *LBL_BP;
    QLabel *LBL_O;
    QFrame *DECO_FRAME;
    QPushButton *BUT_PICK;
    QFrame *frame;
    QLabel *LBL_PHOTO;
    QPushButton *BUT_PICK_ALPHA;
    QFrame *frame_2;
    QLabel *LBL_PHOTO_ALPHA;
    QFrame *DECO_FRAME_2;
    QFrame *DECO_FRAME_3;
    QFrame *DECO_FRAME_4;
    QFrame *DECO_FRAME_5;

    void setupUi(QWidget *CreateForm)
    {
        if (CreateForm->objectName().isEmpty())
            CreateForm->setObjectName("CreateForm");
        CreateForm->resize(1283, 745);
        CreateForm->setMinimumSize(QSize(545, 0));
        horizontalLayoutWidget_2 = new QWidget(CreateForm);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(370, 160, 191, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        COMBO = new QComboBox(horizontalLayoutWidget_2);
        COMBO->setObjectName("COMBO");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        font.setItalic(false);
        COMBO->setFont(font);
        COMBO->setCursor(QCursor(Qt::PointingHandCursor));
        COMBO->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 197, 49);\n"
"font: 700 14px \"Segoe UI\";"));
        COMBO->setInsertPolicy(QComboBox::InsertAtBottom);

        horizontalLayout_2->addWidget(COMBO);

        LBL_AKW = new QLabel(CreateForm);
        LBL_AKW->setObjectName("LBL_AKW");
        LBL_AKW->setGeometry(QRect(40, 120, 311, 41));
        LBL_AKW->setWordWrap(true);
        BUT_CREATE = new QPushButton(CreateForm);
        BUT_CREATE->setObjectName("BUT_CREATE");
        BUT_CREATE->setGeometry(QRect(840, 580, 291, 51));
        BUT_CREATE->setCursor(QCursor(Qt::PointingHandCursor));
        LBL_AT = new QLabel(CreateForm);
        LBL_AT->setObjectName("LBL_AT");
        LBL_AT->setGeometry(QRect(370, 120, 191, 41));
        LBL_AT->setWordWrap(true);
        TEX_DESCR = new QTextEdit(CreateForm);
        TEX_DESCR->setObjectName("TEX_DESCR");
        TEX_DESCR->setGeometry(QRect(40, 160, 311, 101));
        TEX_DESCR->setFont(font);
        TEX_DESCR->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        TEX_DESCR->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 14px \"Segoe UI\";"));
        LBL_NAME = new QLabel(CreateForm);
        LBL_NAME->setObjectName("LBL_NAME");
        LBL_NAME->setGeometry(QRect(40, 30, 251, 41));
        LBL_NAME->setWordWrap(true);
        LBL_ALT_NAME = new QLabel(CreateForm);
        LBL_ALT_NAME->setObjectName("LBL_ALT_NAME");
        LBL_ALT_NAME->setGeometry(QRect(320, 30, 241, 41));
        LBL_ALT_NAME->setWordWrap(true);
        TEX_NAME = new QTextEdit(CreateForm);
        TEX_NAME->setObjectName("TEX_NAME");
        TEX_NAME->setGeometry(QRect(40, 70, 251, 31));
        TEX_NAME->setFont(font);
        TEX_NAME->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        TEX_NAME->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 14px \"Segoe UI\";"));
        TEX_ALT_NAME = new QTextEdit(CreateForm);
        TEX_ALT_NAME->setObjectName("TEX_ALT_NAME");
        TEX_ALT_NAME->setGeometry(QRect(320, 70, 241, 31));
        TEX_ALT_NAME->setFont(font);
        TEX_ALT_NAME->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        TEX_ALT_NAME->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 14px \"Segoe UI\";"));
        LBL_GOAL = new QLabel(CreateForm);
        LBL_GOAL->setObjectName("LBL_GOAL");
        LBL_GOAL->setGeometry(QRect(160, 320, 381, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setUnderline(true);
        LBL_GOAL->setFont(font1);
        LBL_GOAL->setTextFormat(Qt::RichText);
        LBL_GOAL->setWordWrap(true);
        BUT_RESET = new QPushButton(CreateForm);
        BUT_RESET->setObjectName("BUT_RESET");
        BUT_RESET->setGeometry(QRect(840, 470, 291, 51));
        BUT_RESET->setCursor(QCursor(Qt::PointingHandCursor));
        LBL_BS = new QLabel(CreateForm);
        LBL_BS->setObjectName("LBL_BS");
        LBL_BS->setGeometry(QRect(280, 370, 91, 41));
        LBL_BS->setTextFormat(Qt::RichText);
        LBL_BS->setWordWrap(true);
        LBL_AB = new QLabel(CreateForm);
        LBL_AB->setObjectName("LBL_AB");
        LBL_AB->setGeometry(QRect(390, 370, 111, 41));
        LBL_AB->setTextFormat(Qt::RichText);
        LBL_AB->setWordWrap(true);
        horizontalLayoutWidget_5 = new QWidget(CreateForm);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(280, 410, 91, 192));
        horizontalLayoutWidget_5->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout_4 = new QVBoxLayout(horizontalLayoutWidget_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBox_21 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_21->setObjectName("checkBox_21");
        checkBox_21->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_21);

        checkBox_20 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_20->setObjectName("checkBox_20");
        checkBox_20->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_20);

        checkBox_19 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_19->setObjectName("checkBox_19");
        checkBox_19->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_19);

        checkBox_18 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_18->setObjectName("checkBox_18");
        checkBox_18->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_18);

        checkBox_17 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_17->setObjectName("checkBox_17");
        checkBox_17->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_17);

        checkBox_16 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_16->setObjectName("checkBox_16");
        checkBox_16->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_16);

        checkBox_15 = new QCheckBox(horizontalLayoutWidget_5);
        checkBox_15->setObjectName("checkBox_15");
        checkBox_15->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(checkBox_15);

        LBL_D = new QLabel(CreateForm);
        LBL_D->setObjectName("LBL_D");
        LBL_D->setGeometry(QRect(520, 370, 121, 41));
        LBL_D->setAutoFillBackground(false);
        LBL_D->setLineWidth(2);
        LBL_D->setMidLineWidth(0);
        LBL_D->setTextFormat(Qt::RichText);
        LBL_D->setWordWrap(true);
        horizontalLayoutWidget_4 = new QWidget(CreateForm);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(160, 410, 101, 264));
        horizontalLayoutWidget_4->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout_3 = new QVBoxLayout(horizontalLayoutWidget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox_14 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_14->setObjectName("checkBox_14");
        checkBox_14->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_14);

        checkBox_13 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_13->setObjectName("checkBox_13");
        checkBox_13->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_13);

        checkBox_12 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_12->setObjectName("checkBox_12");
        checkBox_12->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_12);

        checkBox_11 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_11->setObjectName("checkBox_11");
        checkBox_11->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_11);

        checkBox_37 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_37->setObjectName("checkBox_37");
        checkBox_37->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_37);

        checkBox_10 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_10->setObjectName("checkBox_10");
        checkBox_10->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_10);

        checkBox_9 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_9->setObjectName("checkBox_9");
        checkBox_9->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_9);

        checkBox_8 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_8);

        checkBox_36 = new QCheckBox(horizontalLayoutWidget_4);
        checkBox_36->setObjectName("checkBox_36");
        checkBox_36->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(checkBox_36);

        horizontalLayoutWidget_6 = new QWidget(CreateForm);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(390, 410, 111, 141));
        horizontalLayoutWidget_6->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout_5 = new QVBoxLayout(horizontalLayoutWidget_6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_26 = new QCheckBox(horizontalLayoutWidget_6);
        checkBox_26->setObjectName("checkBox_26");
        checkBox_26->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(checkBox_26);

        checkBox_25 = new QCheckBox(horizontalLayoutWidget_6);
        checkBox_25->setObjectName("checkBox_25");
        checkBox_25->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(checkBox_25);

        checkBox_24 = new QCheckBox(horizontalLayoutWidget_6);
        checkBox_24->setObjectName("checkBox_24");
        checkBox_24->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(checkBox_24);

        checkBox_23 = new QCheckBox(horizontalLayoutWidget_6);
        checkBox_23->setObjectName("checkBox_23");
        checkBox_23->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(checkBox_23);

        checkBox_22 = new QCheckBox(horizontalLayoutWidget_6);
        checkBox_22->setObjectName("checkBox_22");
        checkBox_22->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(checkBox_22);

        horizontalLayoutWidget_3 = new QWidget(CreateForm);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(40, 410, 101, 192));
        horizontalLayoutWidget_3->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout_2 = new QVBoxLayout(horizontalLayoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(horizontalLayoutWidget_3);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(horizontalLayoutWidget_3);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(checkBox_3);

        checkBox_6 = new QCheckBox(horizontalLayoutWidget_3);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(horizontalLayoutWidget_3);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(checkBox_7);

        checkBox_4 = new QCheckBox(horizontalLayoutWidget_3);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(horizontalLayoutWidget_3);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(checkBox_5);

        checkBox = new QCheckBox(horizontalLayoutWidget_3);
        checkBox->setObjectName("checkBox");
        checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(checkBox);

        horizontalLayoutWidget_7 = new QWidget(CreateForm);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(520, 410, 121, 111));
        horizontalLayoutWidget_7->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout_6 = new QVBoxLayout(horizontalLayoutWidget_7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBox_32 = new QCheckBox(horizontalLayoutWidget_7);
        checkBox_32->setObjectName("checkBox_32");
        checkBox_32->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_6->addWidget(checkBox_32);

        checkBox_31 = new QCheckBox(horizontalLayoutWidget_7);
        checkBox_31->setObjectName("checkBox_31");
        checkBox_31->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_6->addWidget(checkBox_31);

        checkBox_30 = new QCheckBox(horizontalLayoutWidget_7);
        checkBox_30->setObjectName("checkBox_30");
        checkBox_30->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_6->addWidget(checkBox_30);

        checkBox_29 = new QCheckBox(horizontalLayoutWidget_7);
        checkBox_29->setObjectName("checkBox_29");
        checkBox_29->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_6->addWidget(checkBox_29);

        LBL_BP = new QLabel(CreateForm);
        LBL_BP->setObjectName("LBL_BP");
        LBL_BP->setGeometry(QRect(160, 370, 101, 41));
        LBL_BP->setTextFormat(Qt::RichText);
        LBL_BP->setWordWrap(true);
        LBL_O = new QLabel(CreateForm);
        LBL_O->setObjectName("LBL_O");
        LBL_O->setGeometry(QRect(40, 370, 101, 41));
        LBL_O->setTextFormat(Qt::RichText);
        LBL_O->setWordWrap(true);
        DECO_FRAME = new QFrame(CreateForm);
        DECO_FRAME->setObjectName("DECO_FRAME");
        DECO_FRAME->setGeometry(QRect(700, 20, 561, 341));
        DECO_FRAME->setFrameShape(QFrame::StyledPanel);
        DECO_FRAME->setFrameShadow(QFrame::Raised);
        DECO_FRAME->setLineWidth(3);
        BUT_PICK = new QPushButton(DECO_FRAME);
        BUT_PICK->setObjectName("BUT_PICK");
        BUT_PICK->setGeometry(QRect(20, 280, 251, 41));
        BUT_PICK->setCursor(QCursor(Qt::PointingHandCursor));
        frame = new QFrame(DECO_FRAME);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 20, 251, 251));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(5);
        frame->setMidLineWidth(0);
        LBL_PHOTO = new QLabel(frame);
        LBL_PHOTO->setObjectName("LBL_PHOTO");
        LBL_PHOTO->setGeometry(QRect(0, 0, 251, 251));
        BUT_PICK_ALPHA = new QPushButton(DECO_FRAME);
        BUT_PICK_ALPHA->setObjectName("BUT_PICK_ALPHA");
        BUT_PICK_ALPHA->setGeometry(QRect(290, 280, 251, 41));
        BUT_PICK_ALPHA->setCursor(QCursor(Qt::PointingHandCursor));
        frame_2 = new QFrame(DECO_FRAME);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(290, 20, 251, 251));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(5);
        LBL_PHOTO_ALPHA = new QLabel(frame_2);
        LBL_PHOTO_ALPHA->setObjectName("LBL_PHOTO_ALPHA");
        LBL_PHOTO_ALPHA->setGeometry(QRect(0, 0, 251, 251));
        DECO_FRAME_2 = new QFrame(CreateForm);
        DECO_FRAME_2->setObjectName("DECO_FRAME_2");
        DECO_FRAME_2->setGeometry(QRect(20, 310, 641, 381));
        DECO_FRAME_2->setFrameShape(QFrame::StyledPanel);
        DECO_FRAME_2->setFrameShadow(QFrame::Raised);
        DECO_FRAME_2->setLineWidth(3);
        DECO_FRAME_3 = new QFrame(CreateForm);
        DECO_FRAME_3->setObjectName("DECO_FRAME_3");
        DECO_FRAME_3->setGeometry(QRect(20, 20, 561, 261));
        DECO_FRAME_3->setFrameShape(QFrame::StyledPanel);
        DECO_FRAME_3->setFrameShadow(QFrame::Raised);
        DECO_FRAME_3->setLineWidth(3);
        DECO_FRAME_4 = new QFrame(CreateForm);
        DECO_FRAME_4->setObjectName("DECO_FRAME_4");
        DECO_FRAME_4->setGeometry(QRect(820, 560, 331, 91));
        DECO_FRAME_4->setFrameShape(QFrame::StyledPanel);
        DECO_FRAME_4->setFrameShadow(QFrame::Raised);
        DECO_FRAME_4->setLineWidth(3);
        DECO_FRAME_5 = new QFrame(CreateForm);
        DECO_FRAME_5->setObjectName("DECO_FRAME_5");
        DECO_FRAME_5->setGeometry(QRect(820, 450, 331, 91));
        DECO_FRAME_5->setFrameShape(QFrame::StyledPanel);
        DECO_FRAME_5->setFrameShadow(QFrame::Raised);
        DECO_FRAME_5->setLineWidth(3);
        DECO_FRAME_3->raise();
        DECO_FRAME_4->raise();
        DECO_FRAME_5->raise();
        DECO_FRAME->raise();
        DECO_FRAME_2->raise();
        horizontalLayoutWidget_2->raise();
        LBL_AKW->raise();
        BUT_CREATE->raise();
        LBL_AT->raise();
        TEX_DESCR->raise();
        LBL_NAME->raise();
        LBL_ALT_NAME->raise();
        TEX_NAME->raise();
        TEX_ALT_NAME->raise();
        LBL_GOAL->raise();
        BUT_RESET->raise();
        LBL_BS->raise();
        LBL_AB->raise();
        horizontalLayoutWidget_5->raise();
        LBL_D->raise();
        horizontalLayoutWidget_4->raise();
        horizontalLayoutWidget_6->raise();
        horizontalLayoutWidget_3->raise();
        horizontalLayoutWidget_7->raise();
        LBL_BP->raise();
        LBL_O->raise();

        retranslateUi(CreateForm);

        QMetaObject::connectSlotsByName(CreateForm);
    } // setupUi

    void retranslateUi(QWidget *CreateForm)
    {
        CreateForm->setWindowTitle(QCoreApplication::translate("CreateForm", "Form", nullptr));
        LBL_AKW->setText(QCoreApplication::translate("CreateForm", "<html><head/><body><p>Enter Asana Key Words:</p></body></html>", nullptr));
        BUT_CREATE->setText(QCoreApplication::translate("CreateForm", "CREATE ASANA", nullptr));
        LBL_AT->setText(QCoreApplication::translate("CreateForm", "Choise Asana Type:", nullptr));
        LBL_NAME->setText(QCoreApplication::translate("CreateForm", "<html><head/><body><p>Enter Asana Base Name (Hindi Version):</p></body></html>", nullptr));
        LBL_ALT_NAME->setText(QCoreApplication::translate("CreateForm", "<html><head/><body><p>Enter Asana Alternative Name (Meaning Transcription):</p></body></html>", nullptr));
        LBL_GOAL->setText(QCoreApplication::translate("CreateForm", "CHECK ASANA GOAL BENEFITS:", nullptr));
        BUT_RESET->setText(QCoreApplication::translate("CreateForm", "RESET", nullptr));
        LBL_BS->setText(QCoreApplication::translate("CreateForm", "Body System:", nullptr));
        LBL_AB->setText(QCoreApplication::translate("CreateForm", "Anti / Boost:", nullptr));
        checkBox_21->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_20->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_19->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_18->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_17->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_16->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_15->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        LBL_D->setText(QCoreApplication::translate("CreateForm", "Disease (demo):", nullptr));
        checkBox_14->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_13->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_12->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_11->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_37->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_10->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_9->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_8->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_36->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_26->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_25->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_24->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_23->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_22->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_2->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_3->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_6->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_7->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_4->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_5->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_32->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_31->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_30->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        checkBox_29->setText(QCoreApplication::translate("CreateForm", "CheckBox", nullptr));
        LBL_BP->setText(QCoreApplication::translate("CreateForm", "Body Part:", nullptr));
        LBL_O->setText(QCoreApplication::translate("CreateForm", "Concrete Organ:", nullptr));
        BUT_PICK->setText(QCoreApplication::translate("CreateForm", "Pick Main Photo", nullptr));
        LBL_PHOTO->setText(QString());
        BUT_PICK_ALPHA->setText(QCoreApplication::translate("CreateForm", "Pick Alpha Photo", nullptr));
        LBL_PHOTO_ALPHA->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateForm: public Ui_CreateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEFORM_H
