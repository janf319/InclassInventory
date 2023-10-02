#include "Receipt.h"
#include <iostream>
#include <iomanip>

using namespace std;


Receipt::Receipt(Cart* cart, Coupon* coupon) : cart(cart), coupon(coupon) {}

void Receipt::print() {
    std::cout << "======================================" << std::endl;
    std::cout << "            YOUR RECEIPT             " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::left << std::setw(20) << "Item" << std::setw(10) << "Price" << std::setw(10) << "Qty" << std::setw(10) << "Total" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    double subTotal = 0.0;
    for (int i = 0; i < cart->getSize(); i++) {
        Item* item = cart->getItem(i);
        int quantity = 1;  // For simplicity, assume quantity is always 1
        double price = item->getPrice();
        double itemTotal = price * quantity;
        subTotal += itemTotal;
        std::cout << std::left << std::setw(20) << item->getName() << std::setw(10) << "$" << price << std::setw(10) << quantity << std::setw(10) << "$" << itemTotal << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
    double discount = 0.0;
    if (coupon->isEligible(cart)) {
        discount = coupon->getDiscount(cart) * subTotal;
        std::cout << "Discount (" << (coupon->getDiscount(cart) * 100) << "%)\t-$" << discount << std::endl;
    }
    double tax = subTotal * 0.07;  // For simplicity, assume a 7% tax rate
    double total = subTotal + tax - discount;
    std::cout << std::left << std::setw(40) << "Subtotal:" << std::setw(10) << "$" << subTotal << std::endl;
    std::cout << std::left << std::setw(40) << "Tax:" << std::setw(10) << "$" << tax << std::endl;
    std::cout << std::left << std::setw(40) << "Total:" << std::setw(10) << "$" << total << std::endl;
    std::cout << "======================================" << std::endl;
}

