#include<catch2/catch.hpp>

#include <lib2/lib2.h>

TEST_CASE("Test Module2 code")
{
    SECTION("test Bar")
    {
        lib2::Bar B();
        CHECK(true);
    }
}
