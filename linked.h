#include "node.h"

using namespace std;


//Parent linked list
class LinkedList
{
    private:
    node *head;
    public:
    LinkedList();
    ~LinkedList() {;}
    virtual void headInsert() = 0;
    virtual void tailAppend() = 0;
    virtual void removeNode() = 0;
    virtual void insertNodeAfter() = 0;
    virtual void removeNode() = 0;
    virtual node* findnode() = 0;
    virtual void DisplayList() = 0;
    int size();

};

class LinkedListItem : public LinkedList
{
    private:
    Item I;
    public:
    
};

class LinkedListCustomer : public LinkedList
{
    private:
    Customer *C;
    public:
    
}; 