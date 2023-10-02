#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
protected:
    std::string name;
    double price;
    static double delivery;// static variable set outside of class scopr
    static double tip;
public:
    Item(std::string name, double price);
    virtual std::string getCategory() = 0;
    std::string getName();
    static double getDelivery();
    void setDelivery(double delivery);
    double getPrice();
    void setPrice(double price);
    virtual ~Item();
};

class Produce : public Item {
public:
    Produce(std::string name, double price);
    std::string getCategory() override;
    ~Produce();
};

class FreshProduce : public Item
{
private:
    double pounds;
public:
    FreshProduce(string name, double price, double pounds);
    double calcPrice();
    double getPounds();
    void setPounds(double pounds);
    void printOptions();
};
//child class that calculates Item by quantity 
class MeasuredProduct : public Item
{
private:
    double quantity;
public:
    MeasuredProduct(string name, double price, double quantity);
    double calcPrice();
    double getQuantity();
    void setQuantity(double quantity);
};


class Frozen : public Item {
public:
    Frozen(std::string name, double price);
    std::string getCategory() override;
    ~Frozen();
};

class Dairy : public Item {
public:
    Dairy(std::string name, double price);
    std::string getCategory() override;
    ~Dairy();
};

class Dry : public Item {
public:
    Dry(std::string name, double price);
    std::string getCategory() override;
    ~Dry();
};

#endif // ITEM_H
