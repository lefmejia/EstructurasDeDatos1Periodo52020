#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <string>
#include "doctest.h"
#include "sort.h"

TEST_CASE("Sort Numbers")
{
    std::list<int> lst{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46};
    std::list<int> sorted{6, 9, 13, 15, 33, 46, 46, 55, 59, 79, 92};

    sortList(lst);
    for (auto n : lst)
        std::cout << n << " ";
    std::cout << '\n' << std::flush;

    CHECK( lst == sorted );
}

TEST_CASE("Sort Strings")
{
    std::list<std::string> lst{"Honduras", "Guatemala", "El Salvador", "Nicaragua", "Costa Rica", "Panama", "Belice"};
    std::list<std::string> sorted{"Belice", "Costa Rica",  "El Salvador", "Guatemala", "Honduras", "Nicaragua", "Panama"};

    sortList(lst);

    CHECK( lst == sorted );
}
