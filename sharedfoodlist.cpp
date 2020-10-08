#include "sharedfoodlist.h"

SharedFoodList::SharedFoodList()
{
     // Add test data

    m_foodItems.append( FoodItems("Döner", 3.50, QDateTime(QDate(2020, 1, 30), QTime(14, 2, 00)), true) );
    m_foodItems.append( FoodItems("Salat", 2.50, QDateTime(QDate(2020, 2, 30), QTime(13, 2, 00)), false) );
    m_foodItems.append( FoodItems("Pizza", 8.50, QDateTime(QDate(2020, 4, 30), QTime(13, 2, 00)), true) );

}


SharedFoodList* SharedFoodList::instance() { // FEhler suchen

     static SharedFoodList* model = new SharedFoodList(); // QList<FoodItems>* foodItems();  //static SharedFoodList* instance();
     return model;
   }
//SharedFoodList* instance();
 QList<FoodItems>* SharedFoodList::foodItems() { // objkt methode gib uns item zurück
     return &m_foodItems;


 }

