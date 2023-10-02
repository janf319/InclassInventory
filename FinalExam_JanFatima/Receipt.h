#ifndef RECEIPT_H
#define RECEIPT_H

#include "Cart.h"
#include "Coupon.h"

class Receipt {
private:
    Cart* cart;
    Coupon* coupon;
public:
    Receipt(Cart* cart, Coupon* coupon);
    void print();
};

#endif /* RECEIPT_H */

