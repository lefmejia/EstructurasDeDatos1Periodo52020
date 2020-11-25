#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <vector>

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
    : head(nullptr), tail(nullptr), size_(0)
    {}

    LinkedList(const std::initializer_list<TElem>& init);
    //explicit LinkedList(const std::vector<TElem>& v);
    LinkedList(const LinkedList& other);

    ~LinkedList();

    bool operator==(const LinkedList& other) const;

    long size() const { return size_; }
    void pushBack(TElem data);
    void pushFront(TElem data);
    void insertionSort();

private:
    void deleteList(Node* nd);
    Node *head;
    Node *tail;
    long size_;
};

#include "linked_list.cpp"

#endif
