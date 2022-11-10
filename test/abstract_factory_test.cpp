#define CATCH_CONFIG_MAIN
#include "../src/abstract_factory.h"
#include "catch.hpp"

TEST_CASE("sports car")
{
    MakeCar *car_factory = new MakeSportsCar{};
    Car *car = car_factory->make_car();

    REQUIRE(car->get_top_speed() == 150);
    REQUIRE(car->get_handling() == 20);
}

TEST_CASE("hatchback car")
{
    MakeCar *car_factory = new MakeHatchBackCar{};
    Car *car = car_factory->make_car();

    REQUIRE(car->get_top_speed() == 75);
    REQUIRE(car->get_handling() == 10);
}
