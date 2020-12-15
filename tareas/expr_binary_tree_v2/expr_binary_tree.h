#ifndef _EXPR_AST_H
#define _EXPR_AST_H

#include <memory>

enum NodeKind
{
    Add,
    Sub,
    Mul,
    Div,
    Number
};

class Expr
{
public:
    virtual std::string toString() const = 0;
    virtual NodeKind kind() const = 0;
    virtual ~Expr(){};

protected:
    Expr() = default;
};

class BinaryExpr: public Expr
{
protected:
    BinaryExpr(Expr *expr1, Expr *expr2)
    : left(expr1), right(expr2)
    {}

    ~BinaryExpr()
    {
        delete left;
        delete right;
    }

public:
    Expr *left;
    Expr *right;
};

class AddExpr: public BinaryExpr
{
public:
    AddExpr(Expr *expr1, Expr *expr2)
    : BinaryExpr(expr1, expr2)
    {}
    
    NodeKind kind() const override
    { return NodeKind::Add; }

    std::string toString() const override
    {
        return left->toString() + "+" + right->toString();
    }

    ~AddExpr()
    {
        delete left;
        delete right;
    }

};

class SubExpr: public BinaryExpr
{
public:
    SubExpr(Expr *expr1, Expr *expr2)
    : BinaryExpr(expr1, expr2)
    {}

    NodeKind kind() const override
    { return NodeKind::Sub; }
    
    std::string toString() const override
    {
        return left->toString() + "-" + right->toString();
    }

    ~SubExpr()
    {
        delete left;
        delete right;
    }
};

class MulExpr: public BinaryExpr
{
public:
    MulExpr(Expr *expr1, Expr *expr2)
    : BinaryExpr(expr1, expr2)
    {}

    NodeKind kind() const override
    { return NodeKind::Mul; }
    
    std::string toString() const override
    {
        return left->toString() + "*" + right->toString();
    }

    ~MulExpr()
    {
        delete left;
        delete right;
    }
};

class DivExpr: public BinaryExpr
{
public:
    DivExpr(Expr *expr1, Expr *expr2)
    : BinaryExpr(expr1, expr2)
    {}

    NodeKind kind() const override
    { return NodeKind::Div; }
    
    std::string toString() const override
    {
        return left->toString() + "/" + right->toString();
    }

    ~DivExpr()
    {
        delete left;
        delete right;
    }
};

class NumberExpr: public Expr
{
public:
    NumberExpr(int value)
    : value(value)
    {}
    
    NodeKind kind() const override
    { return NodeKind::Number; }

    std::string toString() const override
    {
        return std::to_string(value);
    }
    
    int value;

};

#endif
