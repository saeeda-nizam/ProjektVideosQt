#include "foodlistmodel.h"



FoodListModel::FoodListModel(QList<FoodItems>* foodItems, QObject *parent)
    : QAbstractTableModel(parent), m_foodItems(foodItems)
{
}

QVariant FoodListModel::headerData(int section, Qt::Orientation orientation, int role) const //Section->  gibt mir an welche zeile oder spalte ist das eigentlich
// also wir haben spalte 0 bis 3 und die zailen 0 bis die anzahl
// Orientation -> ich kann spalten kopf eingebe und zeilen beshriften
//Role hat besonder funktion differentziert wofür werden die Dtaen eignetlich bentuzt



{
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal){

            switch (section){

            case 0: return "Name";

            case 1: return "price";

            case 2: return "Date/Time od order";

            case 3: return "Needs Thermo box?";

            }
        }
        else {
            return QString::number(section + 1);
        }


    }
    return QVariant(); // kann alle andere datentypen annehmen ohne das wird compiler das programm abstürz
}

int FoodListModel::rowCount(const QModelIndex &parent) const   //row liefert mir die anzahl  der zeile und Count liefert die anzahl der spalten data
{
    if (parent.isValid())
        return 0;

    return m_foodItems->size();

}

int FoodListModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 4;
}

QVariant FoodListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if( role == Qt::DisplayRole){ //  welche rolle haben wir Display roll
        const FoodItems& item = m_foodItems->at(index.row());

        switch (index.column()){
        case 0: return  item.name();
        case 1:{
            QString priceString;
            priceString.sprintf("%.2f€", item.price());
            return priceString;

        }
        case 2: return item.orderDateTime();
        case 3: return  item.needsThermoBoxTransport() ? "Yes" : "No";
        }
    }
    return QVariant(); // leeres QVariant ist wichtig wenn wir keine geben dann wird program absturz
}

bool FoodListModel::removeRows(int row, int count, const QModelIndex &parent){

    if (row >= rowCount() || row+count-1 >= rowCount()){

        return false;
    }
    beginRemoveRows(parent, row, row+count-1); //da wird von rows ein gelöschen werden

    for (int i = 0; i < count; i++){
        m_foodItems->removeAt((row));

    }

    endRemoveRows();
    return true;
}

//add/edt item
void FoodListModel::addItem (FoodItems item){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    m_foodItems->append(item);

    endInsertRows();

}
void FoodListModel::updateItem(int row, FoodItems item){

    (*m_foodItems)[row] = item;

    emit dataChanged(createIndex(row, 0), createIndex(row, columnCount() -1));


}
