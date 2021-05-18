#include <iostream>
#include <fstream>
#include <string>
#include "Customers.h"
#include "Items.h"

using namespace std;

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

/* ------ CUSTOMERS ------ */
Customer::Customer() {}
Customer::Customer(string id, string name, string address, string phone)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->guest = false;
    this->noOfReturns = 0;
}
string Customer::getId() { return id; }
string Customer::getName() { return name; }
string Customer::getAddress() { return address; }
string Customer::getPhone() { return phone; }
Item *Customer::getItem() { return testItem; }
int Customer::getNoOfReturns() { return noOfReturns; }
bool Customer::isGuest() { return guest; }
void Customer::setItem(Item *item)
{
    this->testItem = item;
}
// ---- Guest -----
Guest::Guest() : Customer()
{
    this->guest = true;
    this->maxRental = 2;
}
Guest::Guest(string id, string name, string address, string phone)
    : Customer(id, name, address, phone)
{
    this->guest = true;
    this->maxRental = 2;
}
bool Guest::borrowItem(/* item here */)
{
    cout << "Borrow Item called" << endl;

    return false;
}

bool Guest::returnItem(/* item here */)
{
    cout << "Return Item called" << endl;

    return false;
}

bool Guest::isGuest() { return guest; }
int Guest::getMaxRental() { return maxRental; }

void input()
{
    string choice;
    int option;
    cin >> choice;
    try
    {
        option = stoi(choice);
    }
    catch (const invalid_argument)
    {
        if (choice == "Exit" || choice == "exit")
        {
            //Exit function here
            return;
        }
        else
        {
            cerr << "Invalid input";
        }
    }
    if (option >= 1 && option <= 10)
    {
        switch (option)
        {
        case 1:;
        case 2:;
        case 3:;
        case 4:;
        case 5:;
        case 6:;
        case 7:;
        case 8:;
        case 9:;
        case 10:;
        }
    }
    else
    {
        cerr << "Invalid Input";
    }
}

void Menu()
{
    cout << "Welcome to Oggy's video store" << endl;
    cout << "Enter an option below." << endl;
    cout << "1. Add a new item, update or delete an existing item" << endl;
    cout << "2. Add new customer or update an existing customer" << endl;
    cout << "3. Promote an existing customer" << endl;
    cout << "4. Rent an item" << endl;
    cout << "5. Return an item" << endl;
    cout << "6. Display all items" << endl;
    cout << "7. Display out-of-stock items" << endl;
    cout << "8. Display all customers" << endl;
    cout << "9. Display group of customers" << endl;
    cout << "10. Search items or customers" << endl;
    cout << "Exit" << endl;
    input();
}

void Test() {
    Item *item1 = new Item("123", "hej", "book", 1, 100, false);
    cout << item1->getId() << endl;
    cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;
    item1->setBorrowed(true);
    cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;

    // Customers
    // Customer base class cant be declared with abstract methods
    // Customer *cus1 = new Customer("10", "Oggy", "District 12", "0702 602 509");
    // cout << "Is guest?: " << boolalpha << cus1->isGuest() << endl;
    // cus1->setItem(item1);
    // Item *item2 = cus1->getItem();
    // cout << item2->getTitle() << endl;

    Guest *guest1 = new Guest("11", "Doggy", "District 14", "0123 012 234");
    cout << "Is guest?: " << boolalpha << guest1->isGuest() << endl;
    cout << "Max rental: " << boolalpha << guest1->getMaxRental() << endl;
}

int main(int argc, char *argv[])
{
    // Checks if the program is executed in the correct format
    if (argc != 2)
    {
        cout << "Invalid amount of argument";
        return -1;
    }

    //Opening the file and checking if it's opened properly
    fstream infile(argv[1]);
    if (!infile)
    {
        cerr << "Error opening file" << endl;
        return -1;
    }
    //UI
    Menu();

    // Tests
    Test();


    return 0;
}
