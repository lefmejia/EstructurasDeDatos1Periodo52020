#include <iostream>
#include "expr_binary_tree.h"
#include "postfix_gen.h"
#include "expr_evaluator.h"

int main()
{
    Expr *n1 = new NumberExpr(45);
    Expr *n2 = new NumberExpr(73);
    Expr *n3 = new NumberExpr(80);
    Expr *n4 = new NumberExpr(13);
    Expr *sum = new AddExpr(n1, n2);
    Expr *sub = new SubExpr(n3, n4);
    Expr *root = new MulExpr(sum, sub);

    std::cout << root->toString() << '\n';

    PostfixGen pgen;
    Evaluator ev;

    std::cout << "Postfix Expression: " << pgen.toPostfix(root) << '\n';
    std::cout << "Evaluated Expression: " << ev.evaluate(root) << '\n';

}
