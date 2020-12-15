#include <stdexcept>
#include "expr_evaluator.h"

int Evaluator::evaluate(Expr *expr)
{
    switch (expr->kind())
    {
        case NodeKind::Add:
            return visit(reinterpret_cast<AddExpr *>(expr));
        case NodeKind::Sub:
            return visit(reinterpret_cast<SubExpr *>(expr));
        case NodeKind::Mul:
            return visit(reinterpret_cast<MulExpr *>(expr));
        case NodeKind::Div:
            return visit(reinterpret_cast<DivExpr *>(expr));
        case NodeKind::Number:
            return visit(reinterpret_cast<NumberExpr *>(expr));
        default:
            throw std::runtime_error("Invalid node");
    }
}

int Evaluator::visit(AddExpr *expr)
{
    int lp = evaluate(expr->left);
    int rp = evaluate(expr->right);

    return rp + lp;
}

int Evaluator::visit(SubExpr *expr)
{
    int lp = evaluate(expr->left);
    int rp = evaluate(expr->right);

    return lp - rp;

}

int Evaluator::visit(MulExpr *expr)
{
    int lp = evaluate(expr->left);
    int rp = evaluate(expr->right);

    return lp * rp;
}

int Evaluator::visit(DivExpr *expr)
{
    int lp = evaluate(expr->left);
    int rp = evaluate(expr->right);

    return lp / rp;

}

int Evaluator::visit(NumberExpr *expr)
{
    return expr->value;
}
