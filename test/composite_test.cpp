#define CATCH_CONFIG_MAIN
#include "../src/composite.h"
#include "catch.hpp"

TEST_CASE("cats in boxes")
{
    std::shared_ptr<CatBoxComponent> outer_box { new Box{} };
    std::shared_ptr<CatBoxComponent> inner_box { new Box{} };
    std::shared_ptr<CatBoxComponent> outer_cat { new Cat{} };
    std::shared_ptr<CatBoxComponent> inner_cat1 { new Cat{} };
    std::shared_ptr<CatBoxComponent> inner_cat2 { new Cat{} };

    inner_box->add_component(inner_cat1);
    inner_box->add_component(inner_cat2);
    outer_box->add_component(inner_box);
    outer_box->add_component(outer_cat);

    REQUIRE(outer_box->is_asleep() == 3);
    inner_box->wakeup();
    REQUIRE(outer_box->is_asleep() == 1);
}
