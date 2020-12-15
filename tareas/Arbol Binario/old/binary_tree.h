#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
template <typename TElem>
class BinarySearchTree
{
public:

    class Node
    {
        public:
        Node(TElem data)
        : data(data), left(nullptr), right(nullptr)
        {}
        void print();
        void print2();
        TElem data;
        Node* left;
        Node* right;
    };
    BinarySearchTree()
    :root(nullptr){}

    void insert(TElem data);
    Node *find(TElem data);
    void print()
    {
        root->print();
        std::cout<<'\n';
    }

    void print2()
    {
        root->print2();
        std::cout<<'\n';
    }

    private:
    Node* root;
};

#include "binary_tree.cpp"

#endif