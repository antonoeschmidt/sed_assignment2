// Used to being able to include header in another header
#ifndef ITEMS_H_
#define ITEMS_H_

#include <string>

using namespace std;

class Item
{
private:
    string id, title, loanType, rentalType;
    int stock;
    float rentalFee;
    bool borrowed;

public:
    Item();
    Item(string id, string title, string loanType, int stock, int rentalFee, bool borrowed);
    ~Item() { ; }

    string getId();
    void setId(string id);
    string getTitle();
    void setTitle(string title);
    string getLoanType();
    void setLoanType(string loanType);
    int getStock();
    void setStock(int stock);
    float getRentalFee();
    void setRentalFee(float rentalFee);
    bool getBorrowed();
    void setBorrowed(bool borrowed);
};

void setIsBorrowed(bool isBorrowed);

class DVD : public Item
{
private:
    string genre;

public:
    DVD();
    DVD(string id, string title, string loanType, int stock, int rentalFee, bool borrowed, string genre);

    string getGenre();
    void setGenre(string genre);
};

class Records : public Item
{
    private:
        string genre;
    
    public:
        Records();
        Records(string id, string title, string loanType, int stock, int rentalFee, bool borrowed, string genre);

        string getGenre();
        void setGenre(string genre);
};

class VideoGames : public Item
{
    private:

    public:
        VideoGames();
        VideoGames(string id, string title, string loanType, int stock, int rentalFee, bool borrowed);

        string getGenre();
        void setGenre(string genre);
};

#endif