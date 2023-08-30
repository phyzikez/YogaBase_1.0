#pragma once
#include <QWidget>

namespace Ui {
    class SearchForm;
}

// UI For Searching Required Asana
class SearchForm : public QWidget
{
    Q_OBJECT
public:
    explicit SearchForm(QWidget *parent = nullptr);
    ~SearchForm();
private:
    Ui::SearchForm *ui;
};
