#include "Item.h"

Item::Item(std::string name, double price) : name(name), price(price) 
{
}

std::string Item::getName() {
    return name;
}

double Item::getPrice() {
    return price;
}

void Item::setPrice(double price) {
    this->price = price;
}

Item::~Item() {}

Produce::Produce(std::string name, double price) : Item(name, price) {}

std::string Produce::getCategory() {
    return "Produce";
}

Produce::~Produce() {}

Frozen::Frozen(std::string name, double price) : Item(name, price) {}

std::string Frozen::getCategory() {
    return "Frozen";
}

Frozen::~Frozen() {}

Dairy::Dairy(std::string name, double price) : Item(name, price) {}

std::string Dairy::getCategory() {
    return "Dairy";
}

Dairy::~Dairy() {}

Dry::Dry(std::string name, double price) : Item(name, price) {}

std::string Dry::getCategory() {
    return "Dry";
}

Dry::~Dry() {}

FreshProduce::FreshProduce(string name, double price, double pounds)
	: Item(name, price)
{//initializing pounds in the constructor in order to calculate it, set it and return it 
	this->pounds = pounds;
}

double FreshProduce::calcPrice()
{
	return getPrice() * pounds;
}

double FreshProduce::getPounds()
{
	return pounds;
}

void FreshProduce::setPounds(double pounds)
{
	this->pounds = pounds;
}

MeasuredProduct::MeasuredProduct(string name, double price, double quantity)
	: Item(name, price)
{//initializing quanitity in constructor in order to calculate it, set it and rturn it
	this->quantity = quantity;
}

double MeasuredProduct::calcPrice()
{
	return getPrice() * quantity;

}

double MeasuredProduct::getQuantity()
{
	return quantity;
}

void MeasuredProduct::setQuantity(double quantity)
{
	this->quantity = quantity;
}
