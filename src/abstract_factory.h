#include <iostream>

//!
//! Abstract product - declares an interface for all Cars.
//!
class Car
{
  public:
    virtual int get_top_speed() = 0; //!< factory method pattern
    virtual int get_handling() = 0;
    virtual ~Car();

  protected:
    const static int _base_speed = 5;
    const static int _base_handling = 5;
};
inline Car::~Car() {} // linker complains when defined in source file...?

//!
//! Concrete product - implements the Car interface.
//!
class SportsCar : public Car
{
  public:
    virtual int get_top_speed() { return _base_speed * 30; }
    virtual int get_handling() { return _base_handling * 4; }
};

//!
//! Concrete product - implements the Car interface.
//!
class HatchBackCar : public Car
{
  public:
    virtual int get_top_speed() { return _base_speed * 15; }
    virtual int get_handling() { return _base_handling * 2; }
};

//!
//! Abstract Factory - declares interface for creating Cars
//!
struct MakeCar
{
    virtual Car *make_car() = 0;
    virtual ~MakeCar();
};
inline MakeCar::~MakeCar() {}

//!
//! Concrete Factory - implements the MakeCar interface to make SportsCars
//!
struct MakeSportsCar : public MakeCar
{
    virtual Car *make_car() { return new SportsCar{}; }
};

//!
//! Concrete Factory - implements the MakeCar interface to make HatchBackCars
//!
struct MakeHatchBackCar : public MakeCar
{
    virtual Car *make_car() { return new HatchBackCar{}; }
};
