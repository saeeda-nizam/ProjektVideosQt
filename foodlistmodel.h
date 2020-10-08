#ifndef FOODLISTMODEL_H
#define FOODLISTMODEL_H
#include "fooditems.h"

#include <QAbstractTableModel>
//#include <QAbstractListModel>

class FoodListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FoodListModel(QList<FoodItems>* foodItems, QObject *parent = nullptr); //parent klasse wenn wir die Praent löschen werden auch die kind objkete mit gelösht

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //Delete rows

    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    //add/edt item
    void addItem(FoodItems item);
    void updateItem(int row, FoodItems item);

private:


   QList<FoodItems>* m_foodItems;
};

#endif // FOODLISTMODEL_H
