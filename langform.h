#pragma once
#include <QWidget>

namespace Ui {
class LangForm;
}

// UI For Choosing App's Language
class LangForm : public QWidget
{
    Q_OBJECT

public:
    explicit LangForm(QWidget *parent = nullptr);
    ~LangForm();
    std::function<void(bool lang)> func;
private:
    Ui::LangForm *ui;
};
