#define CATCH_CONFIG_MAIN
#include "../src/prototype.h"
#include "catch.hpp"

TEST_CASE("get some aluminium")
{
    MetalShop shop;
    std::shared_ptr<Metal> metal = shop.get_metal("1050_aluminium", 3, 3);
    REQUIRE(metal->_width == 3);
}
