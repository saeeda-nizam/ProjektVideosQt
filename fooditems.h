#ifndef FOODITEMS_H
#define FOODITEMS_H
#include "QString"
#include "QDateTime"



class FoodItems
{
public:
    FoodItems();
    FoodItems(QString name, qreal price, QDateTime orderDateTime, bool needsThermaBoxTransport):
        m_name(name), m_price(price), m_orderDateTime(orderDateTime), m_needsThermoBoxTransport(needsThermaBoxTransport)
    {

    }

    //const -> konstanten signalisiert uns eben dem aufrufe das dises Funktion member oder methode das objekt nicht ändert
    QString name() const;
    void setName(const QString &name);

    qreal price() const;
    void setPrice(const qreal &price);

    QDateTime orderDateTime() const;
    void setOrderDateTime(const QDateTime &orderDateTime);

    bool needsThermoBoxTransport() const;
    void setNeedsThermoBoxTransport(bool needsThermoBoxTransport);

private:
    QString m_name; //attribute
    qreal m_price;
    QDateTime m_orderDateTime;
    bool m_needsThermoBoxTransport;
};

#endif // FOODITEMS_H
