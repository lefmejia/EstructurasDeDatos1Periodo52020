#include "linked_list.h"
#include <iostream>
int LinkedList::size() const
{
    if(head==nullptr)
        return 0;

    Node *n = head;
    int sz = 0;

    while(n != nullptr)
    {
        sz++;
        n = n->next;
    }
    
    return sz;
}

void LinkedList::pushBack(int data)
{
    Node *newn = new Node(data);

    if (head==nullptr)
    {
        head = tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
    
}

void LinkedList::pushFront(int data)
{
    Node *newn = new Node(data);

    if (head==nullptr)
    {
        head = tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
}

void LinkedList::print() const
{
    std::cout<<"[";

    Node *n = head;

    while(n!= nullptr)
    {
        std::cout<<n->data<<", ";
        n = n->next;
    }

    std::cout<< " ]";
}