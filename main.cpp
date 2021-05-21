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

FileHandler fileHandler;

void displayItem(vector<Item *> items)
{
    cout << "----------Item List----------" << endl;
    for (auto &i : items)
    {
        cout << "ID: " << i->getId() << " | "
             << "Title:" << i->getTitle() << " | "
             << "Loan Type:" << i->getLoanType() << " | "
             << "Stock:" << i->getStock() << " | "
             << "Fee: " << i->getRentalFee() << " USD"
             << " | "
             << "Available: " << boolalpha << i->isAvaliable() << endl;
    }
    cout << "-----------------------------" << endl;
}

void displayCustomer(vector<Customer *> customers)
{
    cout << "----------Customer List----------" << endl;
    for (auto &i : customers)
    {
        cout << "ID: " << i->getId() << " | "
             << "Name:" << i->getName() << " | "
             << "Address:" << i->getAddress() << " | "
             << "Phone Number:" << i->getPhone();
        vector<string> items = i->getItems();
		if (items.size() > 0)
		{
			for (int j = 0; j < items.size(); j++)
			{
				cout << items[j] << endl;
			}
		}
    }   
    cout << "-----------------------------" << endl;
}

void deleteItem(vector<Item *> items)
{
    cout << "Items:" << endl;
    displayItem(items);
}

void addItem(vector<Item *> items)
{
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
        DVD *disc = new DVD(id, title, loan, stock, fee, genre);
        items.push_back(disc);
        fileHandler.writeItemsFile(items);
        delete disc;
    }
    if (type == REC)
    {
        cout << "Enter genre: ";
        cin >> genre;
        Record *record = new Record(id, title, loan, stock, fee, genre);
        items.push_back(record);
        fileHandler.writeItemsFile(items);
        delete record;
    }
    if (type == GA)
    {
        VideoGames *videoGame = new VideoGames(id, title, loan, stock, fee);
        items.push_back(videoGame);
        fileHandler.writeItemsFile(items);
        delete videoGame;
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
    cout << "0. Exit" << endl;
}

bool handleItem(vector<Item *> items)
{
    bool exit = false;
    while (!exit)
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
                exit = true;
                return true;
            case 1:
                addItem(items);
                break;
            case 2:
                deleteItem(items);
                break;
            case 3:;
            }
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
            // addItem();
        case 2:;
        }
    }
    return false;
}

void input(vector<Item *> items)
{
    bool exit = false;
    while (!exit)
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
        case 0:
            exit = true;
            break;
        case 1:
            handleItem(items);
            break;
        case 2:
            break;
        default:
            cerr << "Incorrect Use";
            break;
        }
    }
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

    // FileHandler fileHandler;
    vector<Item *> items;
    vector<Customer *> customers;

    customers = fileHandler.readCustomerFile();
    displayCustomer(customers);

    items = fileHandler.readItemsFile();
    displayItem(items);

    //UI
    items = fileHandler.readItemsFile();
    input(items);

    return 0;
}
