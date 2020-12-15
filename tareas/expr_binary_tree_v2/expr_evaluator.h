#ifndef _EXPR_EVALUATOR_
#define _EXPR_EVALUATOR_


#include <string>
#include "expr_binary_tree.h"

class Evaluator
{
public:
    Evaluator() = default;

    int evaluate(Expr *expr);

private:
    int visit(AddExpr *expr);
    int visit(SubExpr *expr);
    int visit(MulExpr *expr);
    int visit(DivExpr *expr);
    int visit(NumberExpr *expr);
};

#endif
