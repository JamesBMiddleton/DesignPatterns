#include "prototype.h"

Aluminium::Aluminium(int length, int width, int grade)
    : Metal{length, width}, _grade{grade}
{
}

std::shared_ptr<Metal> Aluminium::Clone() const
{
    return std::shared_ptr<Metal>{new Aluminium{*this}};
}

Steel::Steel(int length, int width, bool is_stainless)
    : Metal{length, width}, _is_stainless{is_stainless}
{
}

std::shared_ptr<Metal> Steel::Clone() const
{
    return std::shared_ptr<Metal>{new Steel{*this}};
}

MetalShop::MetalShop()
{
    prototypes.insert(
        {"stainless steel", std::shared_ptr<Metal>{new Steel{10, 10, true}}});

    prototypes.insert({"1050_aluminium",
                       std::shared_ptr<Metal>{new Aluminium{10, 10, 1050}}});
}

std::shared_ptr<Metal> MetalShop::get_metal(std::string name, int length,
                                            int width)
{
    std::shared_ptr<Metal> p = prototypes[name]->Clone();
    p->_length = length;
    p->_width = width;
    return p;
}
