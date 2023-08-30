#include "createform.h"
#include "ui_createform.h"

CreateForm::CreateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateForm)
{
    ui->setupUi(this);
    this->setFixedWidth(1283);
    this->setFixedHeight(745);
}

CreateForm::~CreateForm()
{
    delete ui;
}
