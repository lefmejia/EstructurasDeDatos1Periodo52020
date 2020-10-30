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
    bool first = true;
    while(n!= nullptr)
    {
        if (first) first = false;
        else std::cout<<", ";

        std::cout<<n->data;
        n = n->next;
    }

    std::cout<< " ]";
}

LinkedList::Node* LinkedList::find(int elem)
{
    Node *n = head;

    while(n!= nullptr)
    {
        if(n->data==elem)
            return n;
        n = n->next;
    }

    std::cout<<"Element not in list";
    return nullptr;
}

LinkedList::Node* LinkedList::findMax()
{
    Node *n = head;
    Node *max = head;

    while(n!= nullptr)
    {
        if(n->data > max->data)
            max = n;

        n = n->next;
    }

    return max;
}

LinkedList::Node* LinkedList::findMin()
{
    Node *n = head;
    Node *min = head;

    while(n!= nullptr)
    {
        if(n->data < min->data)
            min = n;
        
        n = n->next;
    }

    return min;
}