#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList(const std::initializer_list<int>& init)
{
    head = nullptr;
    tail = nullptr;
    for(int n: init)
    {
        pushBack(n);
    }
}

LinkedList::LinkedList(const LinkedList& other)
{
    head = nullptr;
    tail=nullptr;
    Node* newn = other.head;
    while(newn!=nullptr)
    {
        pushBack(newn->data);
        newn = newn->next;
    }
}

LinkedList::~LinkedList()
{
    deleteList(head);
}

void LinkedList::deleteList(Node* nd)
{

    if(nd->next==nullptr)
    {
        delete nd;
        return;
    }
    else
    {
        deleteList(nd->next);
        delete nd;
        return;
    }
    
}

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

void LinkedList::reverse()
{
    LinkedList newList;

    Node* n = head;
    while(n!= nullptr)
    {
        newList.pushFront(n->data);
        n = n->next;
    }

    deleteList(head);
    head = nullptr;
    tail = nullptr;

    n = newList.head;

    while(n!= nullptr)
    {
        pushBack(n->data);
        n = n->next;
    }
}