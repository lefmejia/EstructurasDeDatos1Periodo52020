#ifndef ARITH_EXPR_H
#define ARITH_EXPR_H


enum class Operator
{
    Add,
    Sub,
    Mult,
    Div
};

enum class DataKind
{
    Operator,
    Number
};

struct ExprData
{
    DataKind kind;
    union{
        Operator oper;
        int number;
    };
};

#endif