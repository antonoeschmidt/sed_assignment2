
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>

using namespace std;

class FileHandlar // handlar class
{
public:
	//constructor and destructor
	FileHandlar();
	~FileHandlar();



	// check and write to customer list text file
	bool isCustomerFile();
	bool writeCustomerFile(string line);
	bool readCustomerFile();


	// check if item text file exist
	bool isItemFile();
	bool readItemFile();


private:
	// declare variable
	char* temp_array;
	string customerPrperties[7];
	string* customerItemList;
};