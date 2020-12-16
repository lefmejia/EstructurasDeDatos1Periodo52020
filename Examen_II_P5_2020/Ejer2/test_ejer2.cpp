#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include "doctest.h"
#include "binary_tree.h"

TEST_CASE("Binary Search Tree Inorder: Numbers")
{
    std::initializer_list<int> ilst{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46};
    BinarySearchTree<int> bst;

    for (auto n : ilst)
        bst.insert(n);

    std::list<int> lst = bst.inorder();
    std::list<int> sorted{6, 9, 13, 15, 33, 46, 55, 59, 79, 92};

    CHECK( lst == sorted );
}

TEST_CASE("Binary Search Tree Inorder: Strings")
{
    std::initializer_list<std::string> ilst{"Honduras", "Guatemala", "El Salvador", "Nicaragua", "Costa Rica", "Panama", "Belice"};
    BinarySearchTree<std::string> bst;

    for (auto n : ilst)
        bst.insert(n);

    std::list<std::string> lst = bst.inorder();
    std::list<std::string> sorted{"Belice", "Costa Rica",  "El Salvador", "Guatemala", "Honduras", "Nicaragua", "Panama"};

    CHECK( lst == sorted );
}
