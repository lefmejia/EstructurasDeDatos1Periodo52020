#include "expr_binary_tree.h"

std::string ExprBinaryTree::toString() const
{
    ToStringVisitor visitor;

    return visitor.visitNode(root);
}

std::string ExprBinaryTree::ToStringVisitor::visitNode(const Node *n)
{
    if (n->isOperation())
        return visitOperation(n);
    else if (n->isNumber())
        return visitNumber(n);
    else
        return "";
}

std::string ExprBinaryTree::ToStringVisitor::visitOperation(const Node *n)
{
    std::string str;
    bool pare = false;
    if((n->oper() == Operator::Mult || n->oper() == Operator::Div) && (n->left()->oper() == Operator::Add || n->left()->oper() == Operator::Sub))
    {
        str+="(";
        pare = true;
    }

    str += visitNode(n->left());
    if(pare)
        str+=")";
    pare = false;

    switch (n->oper())
    {
        case Operator::Add: str += "+"; break;
        case Operator::Sub: str += "-"; break;
        case Operator::Mult: str += "*"; break;
        case Operator::Div: str += "/"; break;
    }

    if((n->oper() == Operator::Mult || n->oper() == Operator::Div) && (n->right()->oper() == Operator::Add || n->right()->oper() == Operator::Sub))
    {
        str+="(";
        pare = true;
    }
    
    str += visitNode(n->right());
    if(pare)
        str+=")";

    return str;
}

std::string ExprBinaryTree::ToStringVisitor::visitNumber(const Node *n)
{
    return std::to_string(n->number());
}