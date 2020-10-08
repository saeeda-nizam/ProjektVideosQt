#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include "foodlistmodel.h"
#include <QItemSelectionModel>
#include <QItemSelection>

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_actionRemove_item_triggered();
    void tableSelectionChanged(const QItemSelection&selected);

    void on_actionAdd_Item_triggered();

    void on_actionEdit_Item_triggered();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::FrmMain *ui;

    FoodListModel* m_foodListModel;
};
#endif // FRMMAIN_H
