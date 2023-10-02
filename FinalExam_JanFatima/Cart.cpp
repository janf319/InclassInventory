#include "Cart.h"

void Cart::addItem(Item* item) {
    items.push_back(item);
}

void Cart::removeItem(int index) {
    items.erase(items.begin() + index);
}

void Cart::updatePrice(int index, double newPrice) {
    items[index]->setPrice(newPrice);
}

double Cart::getTotal() {
    double total = 0;
    for (Item* item : items) {
        total += item->getPrice();
    }
    return total;
}

int Cart::getSize() {
    return items.size();
}

Item* Cart::getItem(int index) {
    return items[index];
}
