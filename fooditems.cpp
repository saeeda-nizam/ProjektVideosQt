#include "fooditems.h"

FoodItems::FoodItems()
{

}

QString FoodItems::name() const
{
    return m_name;
}

void FoodItems::setName(const QString &name)
{
    m_name = name;
}

qreal FoodItems::price() const
{
    return m_price;
}

void FoodItems::setPrice(const qreal &price)
{
    m_price = price;
}

QDateTime FoodItems::orderDateTime() const
{
    return m_orderDateTime;
}

void FoodItems::setOrderDateTime(const QDateTime &orderDateTime)
{
    m_orderDateTime = orderDateTime;
}

bool FoodItems::needsThermoBoxTransport() const
{
    return m_needsThermoBoxTransport;
}

void FoodItems::setNeedsThermoBoxTransport(bool needsThermoBoxTransport)
{
    m_needsThermoBoxTransport = needsThermoBoxTransport;
}
