#include <stdexcept>
#include <memory>
#include <vector>

//! 
//! Component - declares interface for cats and boxes.
//!
class CatBoxComponent
{
  public:
    virtual void add_component(std::shared_ptr<CatBoxComponent> component) = 0;
    virtual int is_asleep() const = 0;
    virtual void wakeup() = 0;
    virtual ~CatBoxComponent() = default;
};

//!
//! Leaf - a primitive object - it has no children.
//!
class Cat : public CatBoxComponent
{
  public:
    void add_component(std::shared_ptr<CatBoxComponent> component) override;
    int is_asleep() const override { return _sleeping; }
    void wakeup() override { _sleeping = false; }

  private:
    bool _sleeping = true;
};

//! 
//! Composite - stores cats and redirects requests to all cats it stores.
//!
class Box : public CatBoxComponent
{
  public:
    void add_component(std::shared_ptr<CatBoxComponent> component) override;
    int is_asleep() const override;
    void wakeup() override;

  private:
    std::vector<std::shared_ptr<CatBoxComponent>> _components;
};
