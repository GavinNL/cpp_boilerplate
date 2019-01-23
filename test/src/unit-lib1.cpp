#include<catch2/catch.hpp>

#include <lib1/lib1.h>

TEST_CASE("Test Boilerplate Lib1 code")
{
    SECTION("test foo")
    {
        CHECK(lib1::foo(5) == 7);
    }
}
