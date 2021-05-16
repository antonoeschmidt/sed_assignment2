#include "node.h"

using namespace std;

node::node()
{
    this->next = NULL;
}

node::node(node *nextNode)
{
    this->next = nextNode;
}

void node::setNext(node *nextNode)
{
    this->next = nextNode;
}

node* node::getNext()
{
    return this->next;
}

nodeItem::nodeItem(Item data, node *nextNode) : node(nextNode)
{
    this->I = data;
}

Item* nodeItem::getItem()
{
    return &I;
}

void nodeCustomer::setCustomer(Customer *data)
{
    this->C = data;
}

nodeCustomer::nodeCustomer(Customer *data, node *nextNode) : node(nextNode)
{
    this->C = data;
}

Customer* nodeCustomer::getCustomer()
{
    return this->C;
}


void nodeCustomer::setCustomer(Customer *data)
{
    this->C = data;
}