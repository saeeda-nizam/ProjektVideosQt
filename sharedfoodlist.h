#ifndef SHAREDFOODLIST_H
#define SHAREDFOODLIST_H
#include "QList"
#include "QDateTime"

#include "fooditems.h"


class SharedFoodList // Diese klasse nur da für da
{
private:
    SharedFoodList();

public:

    QList<FoodItems>* foodItems();

    static SharedFoodList* instance(); // gebe immer das gleich objkt züruck


private:
    QList<FoodItems> m_foodItems;

};

#endif // SHAREDFOODLIST_H
