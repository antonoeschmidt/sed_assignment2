#include <string>

using namespace std;

class Item
{
private:
    string id, title, rentalType, loanType;
    int stock, rentalFee;
    bool borrowed;

public:
    Item();
    Item(string _id, string _title, string _rentalType, int _stock, int _rentalFee, bool _isBorrowed);
    // ~Item();

    string getId();
    string getTitle();
    string getRentalType();
    string getLoanType();
    int getStock();
    int getRentalFee();
    bool isBorrowed();
};