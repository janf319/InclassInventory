#ifndef COUPON_H
#define COUPON_H

#include "Cart.h"

class Coupon {
public:
    virtual bool isEligible(Cart* cart) = 0;
    virtual double getDiscount(Cart* cart) = 0;
    virtual ~Coupon() {}
};

class FrozenDiscount : public Coupon {
public:
    bool isEligible(Cart* cart) override;
    double getDiscount(Cart* cart) override;
};

class TaxCoupon : public Coupon {
private:
    double taxRate;
public:
    TaxCoupon(double taxRate) : taxRate(taxRate) {}
    bool isEligible(Cart* cart) override {
        // tax coupon is always eligible
        return true;
    }
    double getDiscount(Cart* cart) override {
        // calculate the discount based on the tax rate and total price
        return taxRate * cart->getTotal();
    }
};
#endif /* COUPON_H */