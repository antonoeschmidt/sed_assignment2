#include <items.h>

/* ------ ITEMS ------ */
Item::Item()
{
    this->id = "I123-1993";
    this->title = "c++ rules";
    this->loanType = "2-day";
    this->stock = 3;
    this->rentalFee = 496;
    this->borrowed = false;
}

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

DVD::DVD() : Item()
{
    this->genre = "Action";
}

DVD::DVD(string id, string title, string loanType, int stock, int rentalFee, bool borrowed, string genre) : Item(id, title, loanType, stock, rentalFee, borrowed)
{
    this->genre = genre;
}
string DVD::getGenre() { return genre; }

Records::Records(string id, string title, string loanType, int stock, int rentalFee, bool borrowed, string genre) : Item(id, title, loanType, stock, rentalFee, borrowed)
{
    this->genre = genre;
}
string Records::getGenre() { return genre; }

VideoGames::VideoGames(string id, string title, string loanType, int stock, int rentalFee, bool borrowed) : Item(id, title, loanType, stock, rentalFee, borrowed)
{
}