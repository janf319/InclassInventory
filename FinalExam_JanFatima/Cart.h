#ifndef CART_H
#define CART_H

#include <vector>
#include "Item.h"

class Cart {
private:
    std::vector<Item*> items;
public:
    void addItem(Item* item);
    void removeItem(int index);
    void updatePrice(int index, double newPrice);
    double getTotal();
    int getSize();
    Item* getItem(int index);
};

#endif /* CART_H */

