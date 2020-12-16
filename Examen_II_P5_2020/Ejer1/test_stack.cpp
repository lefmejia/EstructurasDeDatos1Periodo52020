#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include "doctest.h"
#include "stack.h"

TEST_CASE("Stack of Ints")
{
    std::initializer_list<int> lst_push{59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46};
    std::initializer_list<int> lst_pop{46, 6, 92, 79, 15, 55, 33, 9, 46, 13, 59};
    Stack<int> stk(lst_push.size());

    for (auto n : lst_push)
        REQUIRE_NOTHROW( stk.push(n) );

    for (auto n : lst_pop)
        CHECK( stk.pop() == n);
}

TEST_CASE("Stack of Strings")
{
    std::initializer_list<std::string> lst_push({"Honduras", "Guatemala", "El Salvador", "Nicaragua", "Costa Rica", "Panama", "Belice"});
    std::initializer_list<std::string> lst_pop({"Belice", "Panama", "Costa Rica", "Nicaragua", "El Salvador", "Guatemala", "Honduras"});
    Stack<std::string> stk(lst_push.size());

    for (auto n : lst_push)
        REQUIRE_NOTHROW( stk.push(n) );

    for (auto n : lst_pop)
        CHECK( stk.pop() == n);
}

TEST_CASE("Stack overflow")
{
    Stack<int> stk(2);

    REQUIRE_NOTHROW( stk.push(0) );
    REQUIRE_NOTHROW( stk.push(1) );
    REQUIRE_THROWS( stk.push(2) );
}

TEST_CASE("Stack underflow")
{
    Stack<int> stk(2);

    REQUIRE_NOTHROW( stk.push(0) );
    REQUIRE_NOTHROW( stk.push(1) );
    REQUIRE_NOTHROW( stk.pop() );
    REQUIRE_NOTHROW( stk.pop() );
    
    REQUIRE_THROWS( stk.pop() );
}
