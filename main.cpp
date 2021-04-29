#include <iostream>
#include <string>
#include "header.h"

using namespace std;

Item::Item(string _id, string _title, string _rentalType, int _stock, int _rentalFee, bool _borrowed)
{
    this->id = _id;
    this->title = _title;
    this->rentalType = _rentalType;
    this->stock = _stock;
    this->rentalFee = _rentalFee;
    this->borrowed = _borrowed;
}

string Item::getId() { return id; }
string Item::getTitle() { return title; }
string Item::getRentalType() { return rentalType; }
int Item::getStock() { return stock; }
int Item::getRentalFee() { return rentalFee; }
bool Item::isBorrowed() { return borrowed; }

// void Item::setIsBorrowed(bool _isBorrowed)
// {
//     this->isBorrowed = _isBorrowed;
// }

int main(int argc, char const *argv[])
{

    Item it("123", "hej", "book", 1, 100, false);

    cout << it.getId() << endl;

    return 0;
}
