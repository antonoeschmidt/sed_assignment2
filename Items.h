// Used to being able to include header in another header
#ifndef ITEMS_H_
#define ITEMS_H_

#include <string>

using namespace std;

class Item
{
private:
    string id, title, loanType;
    int stock;
    float rentalFee;
    bool avaliable;

public:
    Item();
    Item(string id, string title, string loanType, int stock, float rentalFee);
    // ~Item() { ; }

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
    bool isAvaliable();
    void setAvaliable(bool avaliable);
    virtual string toText() = 0; // Pure virtual/abstract method

};

class DVD : public Item
{
private:
    string genre;

public:
    DVD();
    DVD(string id, string title, string loanType, int stock, float rentalFee, string genre);

    string getGenre();
    void setGenre(string genre);
    string toText();
};

class Record : public Item
{
    private:
        string genre;
    
    public:
        Record();
        Record(string id, string title, string loanType, int stock, float rentalFee, string genre);

        string getGenre();
        void setGenre(string genre);
        string toText();
};

class VideoGames : public Item
{
    private:

    public:
        VideoGames();
        VideoGames(string id, string title, string loanType, int stock, float rentalFee);
        string toText();
};

#endif