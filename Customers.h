#include <string>

using namespace std;

class Customer
{
private:
    string id, name, address, phone;

public:
    Customer();
    Customer(string id, string name, string address, string phone);
    // ~Customer();
    string getId();
    string getName();
    string getAddress();
    string getPhone();
};