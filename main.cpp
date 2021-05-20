#include <iostream>
#include <fstream>
#include <string>
#include "Customers.h"
#include "Customers.cpp"
#include "Items.h"
#include "items.cpp"
#include "FileHandler.h"
#include "FileHandler.cpp"

using namespace std;

void addItem()
{
    Item tmp;
    enum ItemType
    {
        REC = 1,
        DIS = 2,
        GA = 3
    };
    string title;
    string digit;
    bool borrowed = false;
    string id;
    string year;
    string loan;
    float fee;
    int stock;
    int type;
    string genre;
    cout << "Enter Title: " << endl;
    getline(cin, title);
    cout << "Enter Item 3-digit code: " << endl;
    cin >> digit;
    cout << "Enter year published: " << endl;
    cin >> year;
    id = "I" + digit + "-" + year;
    cout << "Enter loan type: " << endl;
    cin >> loan;
    cout << "Enter amount: " << endl;
    cin >> stock;
    cout << "Enter rental fee: " << endl;
    cin >> fee;
    cout << "Select Item Type: " << endl
         << "(1) Record" << endl
         << "(2) DVD" << endl
         << "(3) Game" << endl;
    cin >> type;
    if (type == DIS)
    {
        cout << "Enter genre: ";
        cin >> genre;
        DVD disc(id, title, loan, stock, fee, borrowed, genre);
    }
    if (type == REC)
    {
        cout << "Enter genre: ";
        cin >> genre;
        Records record(id, title, loan, stock, fee, borrowed, genre);
    }
    if (type == GA)
    {
        VideoGames vidya(id, title, loan, stock, fee, borrowed);
    }
    return;
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
}

bool handleItem()
{
    cout << "Choose action:" << endl
         << "(1) Add" << endl
         << "(2) Delete" << endl
         << "(3) Update" << endl
         << "(0) Back to menu" << endl;
    string a;
    int tmp;
    cin >> a;
    try
    {
        tmp = stoi(a);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid input";
    }
    if (tmp >= 0 && tmp <= 3)
    {
        switch (tmp)
        {
        case 0:
            return true;
        case 1:
            addItem();
        case 2:;
        case 3:;
        }
    }
    return false;
}

bool handleCustomer()
{
    cout << "Choose action:" << endl
         << "(1) Add" << endl
         << "(2) Update" << endl
         << "(0) Back to menu" << endl;
    string a;
    int tmp;
    cin >> a;
    try
    {
        tmp = stoi(a);
    }
    catch (const invalid_argument)
    {
        cerr << "Invalid input";
        return false;
    }
    if (tmp >= 0 && tmp <= 3)
    {
        switch (tmp)
        {
        case 0:
            return true;
        case 1:
            addItem();
        case 2:;
        }
    }
    return false;
}

void input()
{
    Menu();
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
    switch (option)
    {
    case 1:
        bool tmp;
        do
        {
            tmp = handleItem();
        } while (tmp != true);
        input();
        break;
    case 2:;
    default:
        cerr << "Incorrect Use";
    }
}

void Test()
{
    // Item *item1 = new Item("123", "hej", "book", 1, 100, false);
    // cout << item1->getId() << endl;
    // cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;
    // item1->setBorrowed(true);
    // cout << "isBorrowed: " << boolalpha << item1->getBorrowed() << endl;

    // Customers
    // Customer base class cant be declared with abstract methods
    // Customer *cus1 = new Customer("10", "Oggy", "District 12", "0702 602 509");
    // cout << "Is guest?: " << boolalpha << cus1->isGuest() << endl;
    // cus1->setItem(item1);
    // Item *item2 = cus1->getItem();
    // cout << item2->getTitle() << endl;

    // Guest *guest1 = new Guest("11", "Doggy", "District 14", "0123 012 234");
    // cout << "Is guest?: " << boolalpha << guest1->isGuest() << endl;
    // cout << "Max rental: " << boolalpha << guest1->getMaxRental() << endl;

    // Regular *reg1 = new Regular("11", "RegDoggy", "District 1", "0123 012 234");
    // cout << "Is guest?: " << boolalpha << reg1->isGuest() << endl;
}

int main(int argc, char *argv[])
{
    /* Checks if the program is executed in the correct format
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
        }*/
    FileHandler fileHandler;
    vector<Item *> items;
    vector<Customer *> customers;

    customers = fileHandler.readCustomerFile();
    for (int i = 0; i < customers.size(); i++)
    {
        cout << customers[i]->getName() << endl;
    }

    //UI
    input();

    // Tests
    Test();

    fileHandler.writeCustomersFile(customers);
    // Tests

    return 0;
}
