#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include "doctest.h"
#include "array.h"

TEST_CASE("Reverse array")
{
    Array<int> arr({{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46}});

    arr.reverse();

    CHECK( arr.toString() == "[46,6,92,79,15,55,33,9,46,13,59]");
}

TEST_CASE("Is Sorted")
{
    Array<int> arr1({{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46}});
    Array<int> arr2({{6, 9, 13, 15, 33, 46, 46, 55, 59, 79, 92}});

    CHECK( !arr1.isSorted() );
    CHECK( arr2.isSorted() );
}