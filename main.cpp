#include <iostream>
#include <string>
#include "Customers.h"
#include "Items.h"

using namespace std;

Item::Item(string _id, string _title, string _loanType, int _stock, int _rentalFee, bool _borrowed)
{
    this->id = _id;
    this->title = _title;
    this->loanType = _loanType;
    this->stock = _stock;
    this->rentalFee = rentalFee;
    this->borrowed = borrowed;
}
string Item::getID() { return this->id; }
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

DVD::DVD(string _id, string _title, string _loanType, int _stock, int _rentalFee, bool _borrowed, string genre) : Item(_id,_title, _loanType, _stock, _rentalFee, _borrowed)
{

}

int main(int argc, char const *argv[])
{

    Item it("123", "hej", "book", 1, 100, false);

    cout << it.getID() << endl;
    cout << "isBorrowed: " << boolalpha << it.getBorrowed() << endl;
    it.setBorrowed(true);
    cout << "isBorrowed: " << boolalpha << it.getBorrowed() << endl;

    return 0;
}
