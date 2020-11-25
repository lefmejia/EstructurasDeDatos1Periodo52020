#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include "doctest.h"
#include "linked_list.h"

template<typename TElem>
LinkedList<TElem> makeList(const std::initializer_list<TElem>& ilst)
{
    return LinkedList<TElem>(ilst);
}

TEST_CASE("List of Ints")
{
    LinkedList<int> lst({59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46});

    CHECK( lst.size() == 11 );
    CHECK( lst == makeList({59,13,46,9,33,55,15,79,92,6,46}) );
}

TEST_CASE("List of Strings")
{
    LinkedList<std::string> lst({"Honduras", "Guatemala", "El Salvador", "Nicaragua", "Costa Rica", "Panama", "Belice"});

    CHECK( lst.size() == 7 );
    CHECK( lst == makeList<std::string>({"Honduras","Guatemala","El Salvador","Nicaragua","Costa Rica","Panama","Belice"}) );
}

TEST_CASE("Conversion from Vector")
{
    std::vector<long> v{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46};
    LinkedList<long> lst(v);

    CHECK( lst.size() == 11 );
    CHECK( lst == makeList<long>({59,13,46,9,33,55,15,79,92,6,46}) );
}
/*
// Puede comentar este TEST temporalmente
TEST_CASE("Equal comparison to Vector")
{
    std::vector<long> v{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46};
    LinkedList<long> lst(v);

    CHECK( lst.size() == 11 );
    CHECK( lst == v );
}
*/
TEST_CASE("pushBack operation")
{
    LinkedList<int> lst;

    CHECK( lst.size() == 0 );
    for (int i = 0; i < 10; i++)
    {
        lst.pushBack(i);
        CHECK( lst.size() == (i + 1));
    }
    CHECK( lst == makeList({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) );
}

TEST_CASE("pushFront operation")
{
    LinkedList<int> lst;

    CHECK( lst.size() == 0 );
    for (int i = 0; i < 10; i++)
    {
        lst.pushFront(i);
        CHECK( lst.size() == (i + 1));
    }
    CHECK( lst == makeList({9, 8, 7, 6, 5, 4, 3, 2, 1, 0}) );
}

TEST_CASE("Sort")
{
    LinkedList<int> lst({59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46});
    
    lst.insertionSort();

    CHECK( lst == makeList({6,9,13,15,33,46,46,55,59,79,92}));
}
