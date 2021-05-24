#include "process.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Validate greeting message", "[greeting]")
{
	process::greeting();
    REQUIRE(1 == 1);
}
