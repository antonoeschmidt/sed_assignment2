#include <string>

using namespace std;

class Item
{
private:
    string id, title, loanType;
    int stock;
    float rentalFee;
    bool borrowed;

public:
    Item();
    Item(string _id, string _title, string _loanType, int _stock, int _rentalFee, bool _borrowed);
    ~Item() {;}

    string getID();
    void setID(string _id);
    string getTitle();
    void setTitle(string _title);
    string getLoanType();
    void setLoanType(string _loanType);
    int getStock();
    void setStock(int _stock);
    float getRentalFee();
    void setRentalFee(float _rentalFee);
    bool getBorrowed();
    void setBorrowed(bool _borrowed);
};

class DVD : public Item
{
    private:
    string genre;
    public:
    DVD();
    DVD(string _id, string _title, string _loanType, int _stock, int _rentalFee, bool _borrowed, string genre);
};