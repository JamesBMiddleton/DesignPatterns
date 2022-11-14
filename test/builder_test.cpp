#define CATCH_CONFIG_MAIN
#include "../src/builder.h"
#include "catch.hpp"

TEST_CASE("designing a city")
{
    std::shared_ptr<NeoClassicalArchitect> architect{new NeoClassicalArchitect};
    UrbanPlanner planner{};
    planner.design_city(architect);
    NeoClassicalDesigns designs = architect->get_designs();
    REQUIRE(designs.museums == 2);
    REQUIRE(designs.train_stations == 1);
}
