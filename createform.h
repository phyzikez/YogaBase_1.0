#pragma once
#include <QWidget>

namespace Ui {
    class CreateForm;
}

// UI For Inserting User's Asana
class CreateForm : public QWidget
{
    Q_OBJECT
public:
    explicit CreateForm(QWidget *parent = nullptr);
    ~CreateForm();
private:
    Ui::CreateForm *ui;
};
