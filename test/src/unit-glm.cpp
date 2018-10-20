#include<catch2/catch.hpp>

#include<glm/glm.hpp>

TEST_CASE("Test Module2 code")
{
    SECTION("test GLM")
    {
        glm::vec3 x(0.0);
        CHECK(true);
    }
}
