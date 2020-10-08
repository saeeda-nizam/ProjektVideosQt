#ifndef EDITITEMDIALOG_H
#define EDITITEMDIALOG_H

#include <QDialog>
#include "fooditems.h"

namespace Ui {
class EditItemDialog;
}

class EditItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditItemDialog(const FoodItems item, QWidget *parent = nullptr);
    ~EditItemDialog();

    FoodItems item() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditItemDialog *ui;
    FoodItems m_item;
};

#endif // EDITITEMDIALOG_H
