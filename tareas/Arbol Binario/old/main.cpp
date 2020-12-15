#include <iostream>
#include "binary_tree.h"
#include "expr_binary_tree.h"

using namespace std;

int main()
{
    // BinarySearchTree<int> bti;

    // bti.insert(67);
    // bti.insert(35);
    // bti.insert(73);
    // bti.insert(23);
    // bti.insert(87);
    // bti.insert(17);
    // bti.insert(35);
    // bti.insert(77);
    // bti.insert(87);
    // bti.insert(73);
    // bti.insert(38);
    // bti.insert(45);


    // bti.print();

    // BinarySearchTree<ExprData> exprt;

    // ExprData plus;

    // plus.kind = DataKind::Operator;
    // plus.oper = Operator::Add;

    // ExprData num1, num2;
    // num1.kind = DataKind::Number;
    // num1.number = 10;

    // num2.kind= DataKind::Number;
    // num2.number = 20;

    // BinarySearchTree<ExprData>::Node *root = new BinarySearchTree<ExprData>::Node(plus);
    // BinarySearchTree<ExprData>::Node *nnum1 = new BinarySearchTree<ExprData>::Node(num1);
    // BinarySearchTree<ExprData>::Node *nnum2 = new BinarySearchTree<ExprData>::Node(num2);

    auto n1 = new ExprBinaryTree::Node(45);
    auto n2 = new ExprBinaryTree::Node(73);
    auto n3 = new ExprBinaryTree::Node(100);
    auto sum = new ExprBinaryTree::Node(Operator::Add, n1, n2);
    auto mul = new ExprBinaryTree::Node(Operator::Mult, n1, n2);

    ExprBinaryTree expr;

    expr.setRoot(mul);

    return 0;
}