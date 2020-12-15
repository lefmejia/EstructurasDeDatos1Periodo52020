#ifndef _EXPR_BINARY_TREE_H_
#define _EXPR_BINARY_TREE_H_

#include <string>

enum class Operator
{
    Add,
    Sub,
    Mult,
    Div
};

class ExprBinaryTree
{
public:
    enum class NodeKind { Operation, Number };

    class Node
    {
    public:
        Node(int _number)
        : kind(NodeKind::Number), _number(_number)
        {}

        Node(Operator _oper, Node *_left, Node *_right)
        : kind(NodeKind::Operation), _oper(_oper), _left(_left), _right(_right)
        {}

        bool isNumber() const
        { return kind == NodeKind::Number; }

        bool isOperation() const
        { return kind == NodeKind::Operation; }

        int number() const
        { return _number; }

        Node *left() const
        { return _left; }

        Node *right() const
        { return _right; }

        Operator oper() const
        { return _oper; }

    private:
        NodeKind kind;
        union
        {
            struct {
                Node *_left;
                Node *_right;
                Operator _oper;
            };
            int _number;
        };
    };

    void setRoot(Node *n)
    { root = n; }

    Node *getRoot() const
    { return root; }

    std::string toString() const;

private:
    class ToStringVisitor
    {
    public:
        std::string visitNode(const Node *n);
    private:
        std::string visitOperation(const Node *n);
        std::string visitNumber(const Node *n);
    };

private:
    Node *root;
};

#endif
