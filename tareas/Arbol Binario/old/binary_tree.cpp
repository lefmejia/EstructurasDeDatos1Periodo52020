#include "binary_tree.h"
#include <iostream>
using namespace std;

template <typename TElem>
void BinarySearchTree<TElem>::Node::print()
{
    cout<< data <<'\n';

    if(left != nullptr || right != nullptr)
    {
        cout<< "{\n";
        if(left != nullptr)
        {
            left->print();
        }
        if(right != nullptr)
        {
            right->print();
        }

        cout<< '}';
    }

    //cout<< data <<'\n';
}

template <typename TElem>
void BinarySearchTree<TElem>::Node::print2()
    {
        if(left != nullptr)
            left->print2();

        cout<< data << ' ';

        if(right != nullptr)
            right->print2();

        //cout<< data <<'\n';
    }

template <typename TElem>
void BinarySearchTree<TElem>::insert(TElem data)
{
    if(root == nullptr)
    {
        root = new Node(data);
        return;
    }

    Node *n =root;

    do{
        if(n->data == data)
        break;

        if(data< n->data)
        {
            if(n->left == nullptr)
            {
                n->left = new Node(data);
                break;
            }
            else
            {
                n = n->left;
            }
            
        }
        else
        {
            if(n->right == nullptr)
            {
                n->right = new Node(data);
                break;
            }
            else
            {
                n = n->right;
            }
        }
        
    }while(true);
}

template <typename TElem>
typename BinarySearchTree<TElem>::Node *BinarySearchTree<TElem>::find(TElem data)
{
    Node *n =root;

    do{
        if(n == nullptr || n->data == data)
            return n;

        if(data < n->data)
            n = n->left;

        if(data > n->data)
            n = n->right;
        
    }while(true);
}