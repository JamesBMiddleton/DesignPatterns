#include <memory>

//!
//! Abstract product - declares an interface for all Tyres.
//!
class Tyres
{
  public:
    virtual int get_psi() const = 0; //!< factory method pattern
    virtual ~Tyres();

  protected:
    const static int _base_psi = 30;
};
inline Tyres::~Tyres() {} // linker complains when defined in source file...?

//!
//! Concrete product - implements the Tyre interface.
//!
class SportsTyres : public Tyres
{
  public:
    virtual int get_psi() const { return _base_psi * 2; }
};

//!
//! Abstract product - declares an interface for all Engines.
//!
class Engine
{
  public:
    virtual int get_horse_power() const = 0;
    virtual ~Engine();

  protected:
    const static int _base_hp = 100;
};
inline Engine::~Engine() {}

//!
//! Concrete product - implements the Engine interface.
//!
class SportsEngine : public Engine
{
  public:
    virtual int get_horse_power() const { return _base_hp * 5; }
};

//!
//! Abstract Factory - declares interface for creating vehicle components.
//!
struct MakeVehicleComponents
{
    virtual std::unique_ptr<Tyres> make_tyres() = 0;
    virtual std::unique_ptr<Engine> make_engine() = 0;
    virtual ~MakeVehicleComponents();
};
inline MakeVehicleComponents::~MakeVehicleComponents() {}

//!
//! Concrete Factory - implements the MakeVehicleComponents interface.
//!
struct MakeSportsVehicleComponents : public MakeVehicleComponents
{
    virtual std::unique_ptr<Tyres> make_tyres()
    {
        return std::unique_ptr<Tyres>{new SportsTyres{}};
    }

    virtual std::unique_ptr<Engine> make_engine()
    {
        return std::unique_ptr<Engine>{new SportsEngine{}};
    }
};
