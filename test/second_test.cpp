#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/test.h"

TEST_CASE("test") { REQUIRE(1 == 1); }

TEST_CASE("adder")
{ 
    A a;
    REQUIRE( a.add(1, 1) == 2); 
}
