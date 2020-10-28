#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class LinkedList
{

public:
    class Node
    {
        public:
            Node(int val)
            :data(val)
            {}
            Node *next;
            int data;
        private:
            
            
    };

    LinkedList()
    :head(nullptr), tail(nullptr)
    {}

    int size() const;

    void print() const;
    void pushBack(int data);
    void pushFront(int data);
    Node *find(int elem);
    Node *findMin();
    Node *findMax();

    //friend std::ostream& operator << (std::ostream out, const LinkedList& lst); 

private:
    Node* head;
    Node* tail;

};

#endif