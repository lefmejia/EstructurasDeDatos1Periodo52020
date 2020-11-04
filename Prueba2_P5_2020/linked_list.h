#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

template <typename TElem>
class LinkedList
{
public:
    class Node
    {
    public:
        Node(TElem val)
        : data(val), next(nullptr)
        {}
        
        TElem data;
        Node *next;
    };

    LinkedList()
    : head(nullptr), tail(nullptr)
    {}

    LinkedList(const std::initializer_list<TElem>& init);
    LinkedList(const LinkedList<TElem>& other);

    ~LinkedList();

    std::string toString() const;
    int size() const;
    void pushBack(TElem data);
    void pushFront(TElem data);
    void sort();
    bool isSorted();

    template <typename T>
    friend std::ostream& operator << (std::ostream& out, const LinkedList<T>& lst);

private:
    void deleteList(Node* nd);
    Node *head;
    Node *tail;
};

#include "linked_list.cpp"

#endif
