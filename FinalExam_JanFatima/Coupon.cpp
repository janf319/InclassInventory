#include "Coupon.h"

bool FrozenDiscount::isEligible(Cart* cart) {
    for (int i = 0; i < cart->getSize(); i++) {
        if (cart->getItem(i)->getCategory() == "Frozen") {
            return true;
        }
    }
    return false;
}

double FrozenDiscount::getDiscount(Cart* cart) {
    return 0.1; // 10% off
}


