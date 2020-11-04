#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("List of Ints")
{
    LinkedList<int> lst({59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46});

    CHECK( lst.toString() == "[59,13,46,9,33,55,15,79,92,6,46]");
}

TEST_CASE("List of Strings")
{
    LinkedList<std::string> lst({"Honduras", "Guatemala", "El Salvador", "Nicaragua", "Costa Rica", "Panama", "Belice"});

    CHECK( lst.toString() == "[Honduras,Guatemala,El Salvador,Nicaragua,Costa Rica,Panama,Belice]");
}

TEST_CASE("Is Sorted")
{
    LinkedList<int> lst1({59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46});
    LinkedList<int> lst2({6, 9, 13, 15, 33, 46, 46, 55, 59, 79, 92});

    CHECK( !lst1.isSorted() );
    CHECK( lst2.isSorted() );
}

TEST_CASE("Sort")
{
    LinkedList<int> lst({59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46});
    
    lst.sort();

    CHECK( lst.toString() == "[6,9,13,15,33,46,46,55,59,79,92]");
}
