#include <memory>

struct NeoClassicalDesigns
{
    int museums = 0;
    int train_stations = 0;
    int libraries = 0;
};

class Architect
{
  public:
    virtual void design_museum() = 0;
    virtual void design_train_station() = 0;
    virtual void design_library() = 0;
    virtual ~Architect();
};
inline Architect::~Architect(){};

class NeoClassicalArchitect : public Architect
{
  public:
    virtual void design_museum() { designs.museums += 1; }
    virtual void design_train_station() { designs.train_stations += 1; }
    virtual void design_library() { designs.libraries += 1; }
    NeoClassicalDesigns get_designs() { return designs; }

  private:
    NeoClassicalDesigns designs;
};

class UrbanPlanner
{
  public:
    void design_city(std::shared_ptr<Architect> architect) const;
};
inline void
UrbanPlanner::design_city(std::shared_ptr<Architect> architect) const
{
    architect->design_museum();
    architect->design_museum();
    architect->design_train_station();
    architect->design_library();
}
