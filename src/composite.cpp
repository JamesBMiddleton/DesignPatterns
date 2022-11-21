#include "composite.h"

void Cat::add_component(std::shared_ptr<CatBoxComponent> component)
{
    throw std::runtime_error("Can't put a cat in a cat!");
}

void Box::add_component(std::shared_ptr<CatBoxComponent> component)
{
    _components.push_back(component);
}

int Box::is_asleep() const
{
    int sleeping_cats = 0;
    for (std::shared_ptr<CatBoxComponent> c : _components)
        sleeping_cats += c->is_asleep();
    return sleeping_cats;
}

void Box::wakeup()
{
    for (std::shared_ptr<CatBoxComponent> c : _components)
        c->wakeup();
}

