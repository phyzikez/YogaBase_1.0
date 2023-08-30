#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    this->setFixedWidth(400);
    this->setFixedHeight(430);
}

SearchForm::~SearchForm()
{
    delete ui;
}
