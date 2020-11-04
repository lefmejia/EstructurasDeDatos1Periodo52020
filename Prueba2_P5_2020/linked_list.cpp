#include <iostream>
#include <sstream>
#include "linked_list.h"

template <typename TElem>
LinkedList<TElem>::LinkedList(const std::initializer_list<TElem>& init)
{
    head = nullptr;
    tail = nullptr;
    for(TElem n: init)
    {
        pushBack(n);
    }
}

template <typename TElem>
LinkedList<TElem>::LinkedList(const LinkedList<TElem>& other)
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

template <typename TElem>
LinkedList<TElem>::~LinkedList()
{
    deleteList(head);
}

template <typename TElem>
void LinkedList<TElem>::deleteList(Node* nd)
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

template <typename TElem>
int LinkedList<TElem>::size() const
{
    Node *n = head;
    int sz = 0;
    while (n != nullptr)
    {
        sz++;
        n = n->next;
    }

    return sz;
}

template <typename TElem>
void LinkedList<TElem>::pushBack(TElem data)
{
    Node *newn = new Node(data);
    if (head == nullptr)
    {
        head = tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
}

template <typename TElem>
void LinkedList<TElem>::pushFront(TElem data)
{
    Node *newn = new Node(data);
    if (head == nullptr)
    {
        head = tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
}

template <typename TElem>
std::string LinkedList<TElem>::toString() const
{
    std::ostringstream out;
    
    out << "[";
    bool first = true;

    Node *n = head;
    while (n != nullptr)
    {
        if (first) first = false;
        else out << ",";

        out << n->data;
        n = n->next;
    }
    out << "]";
    
    return out.str();
}

template <typename TElem>
bool LinkedList<TElem>::isSorted()
{
    Node* n = head;

    while(n->next!=nullptr)
    {
        if(n->next->data < n->data)
        return false;

        n = n->next;
    }

    return true;
}

template <typename TElem>
void LinkedList<TElem>::sort()
{
    for (int i = 0; i < size(); i++)
    {
        Node* n = head;

        while(n->next != nullptr)
        {
            TElem temp = n->data;
            if(n->data > n->next->data)
            {
                n->data = n->next->data;
                n->next->data = temp;
            }

            n = n->next;
        }
    }
}
