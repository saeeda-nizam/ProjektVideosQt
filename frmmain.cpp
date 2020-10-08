 #include "frmmain.h"
#include "ui_frmmain.h"
#include "sharedfoodlist.h"
#include  <QMessageBox>
#include <QItemSelection>
//#include <QtDebug>
#include "edititemdialog.h"



FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);

            m_foodListModel = new FoodListModel(SharedFoodList::instance()->foodItems(), this); //SharedFoodList* instance();

          //qDebug (SharedFoodList::instance()->foodItems()->first());
          //qDebug() << " QMessage" <<  SharedFoodList::instance()->foodItems()->first().name();
                  ui->tableView->setModel(m_foodListModel); // heir ist fehler

            connect(ui->tableView->selectionModel(), SIGNAL (selectionChanged(QItemSelection, QItemSelection)),this , SLOT(tableSelectionChanged(QItemSelection)));

            ui->menubar->setNativeMenuBar(false);
}



FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::tableSelectionChanged(const QItemSelection &selected){

    bool anySelected = selected.indexes().size()>0;
    ui->actionEdit_Item->setEnabled(anySelected);
      ui->actionRemove_item->setEnabled(anySelected);

}

void FrmMain::on_actionAdd_Item_triggered()
{
    EditItemDialog dialog(FoodItems(), this);
    if (dialog.exec() == QDialog::Accepted){
        m_foodListModel->addItem(dialog.item());

    }

}

void FrmMain::on_actionEdit_Item_triggered()
{
    on_tableView_activated(ui->tableView->currentIndex());
}


void FrmMain::on_actionRemove_item_triggered()  // event
{
    QModelIndex index = ui->tableView->currentIndex();
    if(index.row()>= 0 && index.row() < m_foodListModel->rowCount()){
        if (QMessageBox::question(this, "Remove item", "Do you really want to remove this item?", "Yes, delete it", "No keep it") == 0){
           m_foodListModel->removeRow(index.row()) ;
        }

    }

}


void FrmMain::on_tableView_activated(const QModelIndex &index)
{
    if(index.row()>= 0 && index.row() < m_foodListModel->rowCount()){

      EditItemDialog dialog(SharedFoodList::instance()->foodItems()->at(index.row()), this);
      if(dialog.exec() ==QDialog::Accepted){
      m_foodListModel->updateItem(index.row(), dialog.item());

    }

}

}
