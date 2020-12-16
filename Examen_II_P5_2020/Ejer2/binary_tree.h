#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <list>

template<typename TElem>
class BinarySearchTree
{
public:
    class Node
    {
        public:
        Node(TElem data)
        : data(data), left(nullptr), right(nullptr)
        {}
        void pushData(std::list<TElem>& lis)
        {
            
            if(left != nullptr)
                left->pushData(lis);
            
            lis.push_back(data);

            if(right != nullptr)
                right->pushData(lis);

        }
        TElem data;
        Node* left;
        Node* right;
    };
    BinarySearchTree()
    :root(nullptr){}

    void insert(TElem data)
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
    // Returns a list of the elements of the tree
    // in ascending order.
    std::list<TElem> inorder() const
    {
    
    std::list<TElem> nueva;
    root->pushData(nueva);
    return nueva;
    }
    Node *find(TElem data);

    private:
    Node* root;
};

#endif
