#include "FileHandler.h"
#include "Customers.h"
#include "Items.h"
#include <sstream>
#include <string>

FileHandler::FileHandler() {}
FileHandler ::~FileHandler() {}

bool FileHandler::isCustomerFile() // function to check for the customer file
{
	ifstream _fcount;
	_fcount.open("customers.txt");
	if (_fcount) // check if file can be open
	{
		_fcount.close();
		return true;
	}
	else // check if file can be open
	{
		cout << "Customer file doesn't exist" << endl;
		_fcount.close();
		return false;
	}
}

bool FileHandler::writeCustomersFile(vector<Customer *> customers) // write to customers text file
{
	ofstream f;
	f.open("customers.txt");

	for (int i = 0; i < customers.size(); i++)
	{
		string line = customers[i]->toText();
		f << line << endl;

		vector<string> items = customers[i]->getItems();
		if (items.size() > 0)
		{
			for (int j = 0; j < items.size(); j++)
			{
				f << items[j] << endl;
			}
		}
	}
	f.close();
	return true;
}

vector<Customer *> FileHandler::readCustomerFile(string customerFile) // function read customer file
{
	string line;
	vector<string> strBuff;
	vector<Customer *> customers;
	FileHandler FileHandler;

	if (!FileHandler.isCustomerFile())
	{
		cout << "isCustomerFile : NO" << endl;
		return customers;
	}

	ifstream _fcount; //input customers text file

	// _fcount.open("customers.txt");
	_fcount.open(customerFile);

	while (_fcount)
	{
		getline(_fcount, line); // if file is open get and store value in line
		if (line == "-1")
		{
			cout << "can't open file" << endl;
			break; // if file is not found
		}
		strBuff.push_back(line);
		// line = "";
	}
	_fcount.close();

	for (int i = 0; i < strBuff.size(); i++)
	{
		// maybe its possible to use number of rentals in order to take the next items
		if (strBuff[i][0] == 'I')
		{
			int cusLen = customers.size();
			customers[cusLen - 1]->populateBorrowedItems(strBuff[i]);
		}

		if (strBuff[i][0] == 'C')
		{
			stringstream ss(strBuff[i]);
			vector<string> customerVector;
			while (ss.good())
			{
				string substr;
				getline(ss, substr, ',');
				customerVector.push_back(substr);
			}
			// int subStrLength = customerVector[5].length() - 1; //This handles unwanted whitespace in Type of Customer
			if (customerVector[5] == "Guest")
			{
				Guest *guest = new Guest(customerVector[0], customerVector[1], customerVector[2], customerVector[3]);
				customers.push_back(guest);
			}
			else if (customerVector[5] /*.substr(0, subStrLength)*/ == "Regular")
			{
				Regular *regular = new Regular(customerVector[0], customerVector[1], customerVector[2], customerVector[3]);
				customers.push_back(regular);
			}
			else if (customerVector[5] == "VIP")
			{
				VIP *vip = new VIP(customerVector[0], customerVector[1], customerVector[2], customerVector[3]);
				customers.push_back(vip);
			}
			else
			{
				cout << "No type found. Error." << endl;
			}
		}
	}
	return customers;
}

bool FileHandler::isItemFile()
{
	ifstream _fcount;
	_fcount.open("items.txt");
	if (_fcount) // check if item text file can be open
	{
		_fcount.close();
		return true;
	}
	else
	{
		cout << "Items file doesn't exist" << endl;
		_fcount.close();
		return false;
	}
}

vector<Item *> FileHandler::readItemsFile(string itemFile)
{
	string line;
	vector<string> strBuff;
	vector<Item *> items;
	FileHandler fileHandler;

	if (!fileHandler.isItemFile())
	{
		cout << "isItemFile : NO" << endl;
		return items;
	}

	ifstream _fcount; //input customers text file

	// _fcount.open("items.txt");
	_fcount.open(itemFile);

	while (_fcount)
	{
		getline(_fcount, line); // if file is open get and store value in line
		if (line == "-1")
		{
			cout << "can't open file" << endl;
			break; // if file is not found
		}
		strBuff.push_back(line);
		line = "";
	}
	_fcount.close();

	for (int i = 0; i < strBuff.size(); i++)
	{
		if (strBuff[i][0] == 'I')
		{
			stringstream ss(strBuff[i]);
			vector<string> itemVector;
			while (ss.good())
			{
				string substr;
				getline(ss, substr, ',');
				itemVector.push_back(substr);
			}

			string type = itemVector[2];
			if (itemVector[2] == "Game")
			{
				VideoGames *videoGame = new VideoGames(itemVector[0], itemVector[1], itemVector[3], stoi(itemVector[4]), stof(itemVector[5]));
				items.push_back(videoGame);
			}
			else if (itemVector[2] == "DVD")
			{
				DVD *dvd = new DVD(itemVector[0], itemVector[1], itemVector[3], stoi(itemVector[4]), stof(itemVector[5]), itemVector[6]);
				items.push_back(dvd);
			}
			else if (itemVector[2] == "Record")
			{
				Record *record = new Record(itemVector[0], itemVector[1], itemVector[3], stoi(itemVector[4]), stof(itemVector[5]), itemVector[6]);
				items.push_back(record);
			}
		}
	}
	return items;
}

bool FileHandler::writeItemsFile(vector<Item *> items)
{
	ofstream f;
	f.open("items.txt");

	for (int i = 0; i < items.size(); i++)
	{
		string line = items[i]->toText();
		f << line << endl;
	}
	f.close();

	return true;
}