
#include <string>


// set maximum renting number of video for guest account
#define MAXRENT_GUEST 2

using namespace std;

class Guest : public Member // create class guest, children of class member utilizing inheratance 
{
public:
	//create 2 parameterized constructor for object class guest 
	Guest(string id, string name, string address, string phone, int numRent, int rating, bool status);
	// overloaded
	Guest(string id, string name, string address, string phone, int numRent, int rating);
	//destructor
	~Guest();

	// function for guest account to borrow and return item
	bool rentItem(item* item);
	bool returnItem(item* item);

	// functions retrieve account data (name, id, etc)
	string getId();
	string getName();
	string getAddress();
	string getPhone();
	int getNumOFRents();
	// rating is the account status: 0 for guest, 1 for regular and 2 for VIP
	int getRating();
	int getGiftCount() { return this->giftCount; };

	// functions modify account data
	string setName(string name) { this->name = name; return this->name; };
	string setAddress(string address) { this->address = address; return this->address; };
	string setPhone(string phone) { this->phone = phone; return this->phone; };
	bool setStatus(bool status) { this->status = status; return this->status; };

	int setGiftCountUp() { this->giftCount++; return this->giftCount; };
	int setGiftCountDown() { this->giftCount--; return this->giftCount; };
	// functions increase variable (numrent) when account is renting and decrease the variable when returning
	int setNumOFRents() { numRent++; return numRent; };
	int setRating(int rate) { this->rating = rate; return rating; };
	int setItemRentCountDown() { this->numRent--; return numRent; };
	int setReturnedCount() { this->returned_count++; return returned_count; };
	int setReturnedCount_0() { this->returned_count = 0; return returned_count; };
	int setGiftCount_0() { this->giftCount = 0; return giftCount; };
	int getReturnedCount() { return returned_count; };

	//functions adding and remove item to the list of item
	bool addItemToList(Item* item) { this->list_of_rentals[numRent - 1] = item; return true; };
	bool removeItemFromList(Item* item) { this->list_of_rentals[numRent - 1] = NULL; return true; };
	// function check item rented by the account
	bool checkItemPossess(Item* item);
	// function return customer status
	bool getCustStat() { return this->status; };
	bool setCustStatTrue() { this->status = true; return this->status; };
	bool setCustStatFalse() { this->status = false; return this->status; };
	//bool removeItemFromList();

	bool guestUpgrade(); // function upgrade account
	bool checkCustomerOwnItems(item* item); // function check item own by the account


private:
	// declare account variable data
	string id;
	string name;
	string address;
	string phone;
	int numRent;
	int rating;
	int returned_count;
	int giftCount;
	bool status;
	// create account rental list
	Item* list_of_rentals[MAXRENT_GUEST];

};