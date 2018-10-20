#include<catch2/catch.hpp>

#include <boilerplate/boilerplate.h>

TEST_CASE("Test Boilerplate code")
{
    SECTION("test foo")
    {
        CHECK(boilerplate::foo(5) == 7);
    }
}
