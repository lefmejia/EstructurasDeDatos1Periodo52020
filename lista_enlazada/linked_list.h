#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>

class LinkedList
{

public:
    class Node
    {
        public:
            Node(int val)
            :data(val)
            {}

            friend std::ostream& operator << (std::ostream& out, const Node *nd)
            {
                std::cout << nd->data;
                return out; 
            }
            Node *next;
            int data;
        private:
            
            
    };

    LinkedList()
    :head(nullptr), tail(nullptr)
    {}

    LinkedList(const std::initializer_list<int>& init);
    LinkedList(const LinkedList& other);

    ~LinkedList();

    int size() const;

    void print() const;
    void pushBack(int data);
    void pushFront(int data);
    Node *find(int elem);
    Node *findMin();
    Node *findMax();
    void reverse();

    friend std::ostream& operator << (std::ostream& out, const LinkedList lst)
    {
        lst.print();
        return out; 
    }

private:
    Node* head;
    Node* tail;

};

#endif