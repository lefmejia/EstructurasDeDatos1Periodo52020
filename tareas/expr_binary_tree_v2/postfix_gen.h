#ifndef _POSTFIX_GEN_H
#define _POSTFIX_GEN_H

#include <string>
#include "expr_binary_tree.h"

class PostfixGen
{
public:
    PostfixGen() = default;

    std::string toPostfix(Expr *expr);

private:
    std::string visit(AddExpr *expr);
    std::string visit(SubExpr *expr);
    std::string visit(MulExpr *expr);
    std::string visit(DivExpr *expr);
    std::string visit(NumberExpr *expr);
};

#endif
