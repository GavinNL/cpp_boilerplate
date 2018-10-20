#include<catch2/catch.hpp>
#define FMT_STRING_ALIAS 1
#include<fmt/format.h>
#include<glm/glm.hpp>

TEST_CASE("Test Module2 code")
{
    SECTION("test GLM")
    {
        std::string s = fmt::format("{}", 42);
        CHECK(true);
    }
}

