#include "Guest.h"

// class object constructors
Guest::Guest(string id, string name, string address, string phone, int numRent, int rating, bool status)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->numRent = numRent;
	this->rating = rating;
	this->status = status;
}

Guest::Guest(string id, string name, string address, string phone, int numRent, int rating)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->numRent = numRent;
	this->rating = rating;
	this->status = false;
}

Guest :: ~Guest() {} // destructor

// return value true when item is rented or returned
bool Guest::rentItem(Item* item)
{
	return true;
}
bool Guest::returnItem(Item* item)
{
	return true;
}

// retrieve account data
string Guest::getId() { return this->id; }
string Guest::getName() { return this->name; }
string Guest::getAddress() { return this->address; }
string Guest::getPhone() { return this->phone; }
int Guest::getNumOFRents() { return this->numRent; }
int Guest::getRating() { return this->rating; }

bool Guest::checkItemPossess(Item* item) // check if account is possessing the item if item found return true and vice versa
{
	int i;
	bool found = false;
	for (i = 0; i < this->numRent; i++) // check all of the item in the guest account list
	{
		if (this->list_of_rentals[i] != NULL) // check for the availability of the item
		{
			if (item->getId().compare(this->list_of_rentals[i]->getId()) == 0) // compare the item with the item in guest's list
			{
				found = true;
				break;
			}
		}
	}

	return found;
}

// this function is identical to the above to check for customer own items
bool Guest::checkCustomerOwnItems(Item* item)
{
	int i;
	bool found = false;
	for (i = 0; i < this->numRent; i++)
	{
		if (this->list_of_rentals[i] != NULL)
		{
			if (item->getId().compare(this->list_of_rentals[i]->getId()) == 0)
			{
				found = true;
				break;
			}
		}
	}

	return found;
}
