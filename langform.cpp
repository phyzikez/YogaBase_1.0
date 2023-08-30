#include "langform.h"
#include "ui_langform.h"

LangForm::LangForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LangForm)
{
    ui->setupUi(this);

    connect(ui->EN, &QPushButton::clicked, [=](){
        func(false);
    });
    connect(ui->RU, &QPushButton::clicked, [=](){
        func(true);
    });
}

LangForm::~LangForm()
{
    delete ui;
}
