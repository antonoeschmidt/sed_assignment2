#include "Items.h"
#include <iostream>
using namespace std;

/* ------ ITEMS ------ */
Item::Item()
{
    this->id = "I123-1993";
    this->title = "c++ rules";
    this->loanType = "2-day";
    this->stock = 3;
    this->rentalFee = 496;
    this->avaliable = true;
}

Item::Item(string id, string title, string loanType, int stock, float rentalFee)
{
    this->id = id;
    this->title = title;
    this->loanType = loanType;
    this->stock = stock;
    this->rentalFee = rentalFee;
    this->avaliable = stock > 0;
}
string Item::getId() { return this->id; }
void Item::setId(string id)
{
    this->id = id;
}
string Item::getTitle() { return this->title; }
void Item::setTitle(string title)
{
    this->title = title;
}
string Item::getLoanType() { return this->loanType; }
void Item::setLoanType(string loanType)
{
    this->loanType = loanType;
}

int Item::getStock() { return this->stock; }
void Item::setStock(int stock)
{
    this->stock = stock;
}
float Item::getRentalFee() { return this->rentalFee; }
void Item::setRentalFee(float rentalFee)
{
    this->rentalFee = rentalFee;
}
bool Item::isAvaliable() { return this->avaliable; }
void Item::setAvaliable(bool avaliable)
{
    this->avaliable = avaliable;
}

DVD::DVD() : Item()
{
    this->genre = "Action";
}

DVD::DVD(string id, string title, string loanType, int stock, float rentalFee, string genre) : Item(id, title, loanType, stock, rentalFee)
{
    this->genre = genre;
}
string DVD::getGenre() { return genre; }

void DVD::setGenre(string genre) {this->genre = genre;}
string DVD::toText()
{
    string rentalFee = to_string(this->getRentalFee());
    int size = rentalFee.size();
    rentalFee = rentalFee.substr(0, size - 4);
    cout << rentalFee << endl;
    return this->getId() + "," + this->getTitle() + ",DVD," + this->getLoanType() + "," + to_string(this->getStock()) + "," + rentalFee + "," + this->getGenre();
}

Record::Record(string id, string title, string loanType, int stock, float rentalFee, string genre) : Item(id, title, loanType, stock, rentalFee)
{
    this->genre = genre;
}
Record::Record() : Item()
{
    this->genre = "Disco";
}

string Record::getGenre() { return genre; }

string Record::toText()
{
    string rentalFee = to_string(this->getRentalFee());
    int size = rentalFee.size();
    rentalFee = rentalFee.substr(0, size - 4);
    cout << rentalFee << endl;
    return this->getId() + "," + this->getTitle() + ",Record," + this->getLoanType() + "," + to_string(this->getStock()) + "," + rentalFee + "," + this->getGenre();
}

VideoGames::VideoGames(string id, string title, string loanType, int stock, float rentalFee) : Item(id, title, loanType, stock, rentalFee)

void Record::setGenre(string genre) {this->genre = genre;}

    ;
string VideoGames::toText()
{
    string rentalFee = to_string(this->getRentalFee());
    int size = rentalFee.size();
    rentalFee = rentalFee.substr(0, size - 4);
    cout << rentalFee << endl;
    return this->getId() + "," + this->getTitle() + ",Game," + this->getLoanType() + "," + to_string(this->getStock()) + "," + rentalFee;
}