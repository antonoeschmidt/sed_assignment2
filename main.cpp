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

int main(int argc, char const *argv[])
{

    Item it("123", "hej", "book", 1, 100, false);

    cout << it.getId() << endl;

    return 0;
}
