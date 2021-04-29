#include <string>

using namespace std;

class Customer
{
    private:
    string ID, Name, Address, Phone;
    public:
    Customer();
    ~Customer();
};
    
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

    void setIsBorrowed(bool _isBorrowed);
};