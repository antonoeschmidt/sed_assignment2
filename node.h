#include "Customers.h"
#include "Items.h"

using namespace std;


//Parent node class
class node
{
    public:
        ~node() {;}
        node() {;}
        node(node *nextNode);
        node* getNext();
        void setNext(node *nextNode);

    private:
        node *next;
};

//Item node class
class nodeItem : public node
{
    public:
        ~nodeItem() {;}
        nodeItem() {;};
        nodeItem(Item data, node *nextNode);
        void setItem(Item data);
        Item* getItem();
    private:
        Item I;
};

class nodeCustomer : public node
{
    public:
        ~nodeCustomer() {;}
        nodeCustomer() {;};
        nodeCustomer(Customer *data, node *nextNode);
        void setCustomer(Customer *data);
        Customer* getCustomer();
    private:
        Customer *C;
};