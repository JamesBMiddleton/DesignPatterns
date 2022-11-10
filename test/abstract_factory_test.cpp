#define CATCH_CONFIG_MAIN
#include "../src/abstract_factory.h"
#include "catch.hpp"

TEST_CASE("make some sports vehicle components")
{
    MakeVehicleComponents *vehicle_factory = new MakeSportsVehicleComponents{};
    Tyres *tyres = vehicle_factory->make_tyres();
    Engine *engine = vehicle_factory->make_engine();

    REQUIRE(tyres->get_psi() == 60);
    REQUIRE(engine->get_horse_power() == 500);
}
