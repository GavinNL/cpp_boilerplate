#include<catch2/catch.hpp>

#include <module2/module2.h>

TEST_CASE("Test Module2 code")
{
    SECTION("test Bar")
    {
        module2::Bar B();
        CHECK(true);
    }
}
