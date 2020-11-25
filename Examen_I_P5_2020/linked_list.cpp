#include <iostream>
#include <sstream>
#include "linked_list.h"

template <typename TElem>
LinkedList<TElem>::LinkedList(const std::initializer_list<TElem>& init)
{
    head = nullptr;
    tail = nullptr;
    size_= 0;
    for(TElem n: init)
    {
        pushBack(n);
    }
}
template <typename TElem>
LinkedList<TElem>::LinkedList(const std::vector<TElem>& v)
{
    head = nullptr;
    tail = nullptr;
    size_= 0;
    for(TElem n: v)
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
    size_++;
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

    size_++;
}

template <typename TElem>
bool LinkedList<TElem>::operator==(const LinkedList& other) const
{
    Node* actual1 = head;
    Node* actual2 = other.head;

    while(actual1!=nullptr && actual2!=nullptr)
    {
        if(actual1->data != actual2->data)
            return false;
        
        actual1 = actual1->next;
        actual2 = actual2->next;

        if(actual1 == nullptr && actual2 !=nullptr)
            return false;
        else if(actual1 != nullptr && actual2 ==nullptr)
            return false;
    }

    return true;
}

template <typename TElem>
void LinkedList<TElem>::insertionSort()
{

    Node* actual = head;

    while(actual->next != nullptr)
    {
        if(actual->next->data > actual->data)
            actual = actual->next;
        else
        {
            Node* temp = actual->next;
            actual->next = temp->next;

            if(head->data > temp->data)
            {
                temp->next = head;
                head = temp;

            }
            else
            {
                Node* inpos = head;

                while(temp->data > inpos->next->data)
                    inpos = inpos->next;

                temp->next = inpos->next;
                inpos->next = temp;
            }
            
        }
        
    }

}