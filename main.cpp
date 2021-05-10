#include <iostream>
#include <string>
#include "Customers.h"
#include "Items.h"

using namespace std;

Item::Item(string id, string title, string loanType, int stock, int rentalFee, bool borrowed)
{
    this->id = id;
    this->title = title;
    this->loanType = loanType;
    this->stock = stock;
    this->rentalFee = rentalFee;
    this->borrowed = borrowed;
}
string Item::getId() { return this->id; }
string Item::getTitle() { return this->title; }
int Item::getStock() { return this->stock; }
float Item::getRentalFee() { return this->rentalFee; }
bool Item::getBorrowed() { return this->borrowed; }
void Item::setBorrowed(bool isBorrowed)
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
string Customer::getId() { return id; }
string Customer::getName() { return name; }
string Customer::getAddress() { return address; }
string Customer::getPhone() { return phone; }
Item *Customer::getItem() { return testItem; }
void Customer::setItem(Item *item)
{
    this->testItem = item;
}

DVD::DVD(string id, string title, string loanType, int stock, int rentalFee, bool borrowed, string genre) : Item(id, title, loanType, stock, rentalFee, borrowed)
{
}

int main(int argc, char const *argv[])
{

    // Items
    Item *item1 = new Item("123", "hej", "book", 1, 100, false);
    cout << item1->getId() << endl;
    cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;
    item1->setBorrowed(true);
    cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;

    // Customers
    Customer *cus1 = new Customer("10", "Oggy", "District 12", "0702 602 509");
    cus1->setItem(item1);
    Item *item2 = cus1->getItem();
    cout << item2->getTitle() << endl;

    return 0;
}
