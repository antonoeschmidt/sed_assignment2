#include <iostream>
#include <string>
#include "Customers.h"
#include "Items.h"

using namespace std;

Item::Item(string id, string title, string rentalType, int stock, int rentalFee, bool borrowed)
{
    this->id = id;
    this->title = title;
    this->rentalType = rentalType;
    this->stock = stock;
    this->rentalFee = rentalFee;
    this->borrowed = borrowed;
}
string Item::getId() { return id; }
string Item::getTitle() { return title; }
string Item::getRentalType() { return rentalType; }
int Item::getStock() { return stock; }
int Item::getRentalFee() { return rentalFee; }
bool Item::isBorrowed() { return borrowed; }
void Item::setIsBorrowed(bool isBorrowed)
{
    this->borrowed = isBorrowed;
}

Customer::Customer(string id, string name, string address, string phone)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
}

int main(int argc, char const *argv[])
{

    Item it("123", "hej", "book", 1, 100, false);

    cout << it.getId() << endl;
    cout << "isBorrowed: " << boolalpha << it.isBorrowed() << endl;
    it.setIsBorrowed(true);
    cout << "isBorrowed: " << boolalpha << it.isBorrowed() << endl;

    return 0;
}
