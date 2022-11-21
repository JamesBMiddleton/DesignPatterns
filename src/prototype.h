#include <map>
#include <memory>
#include <string>

//!
//! Abstract product
//!
struct Metal
{
    virtual std::shared_ptr<Metal> Clone() const = 0;
    virtual ~Metal();
    int _length;
    int _width;

  protected:
    Metal(int length, int width) : _length{length}, _width{width} {};
};
inline Metal::~Metal() {}

//!
//! Concrete product
//!
struct Aluminium : public Metal
{
    Aluminium(int length, int width, int grade);
    virtual std::shared_ptr<Metal> Clone() const;
    int _grade;
};

//!
//! Concrete product
//!
struct Steel : public Metal
{
    Steel(int length, int width, bool is_stainless);
    virtual std::shared_ptr<Metal> Clone() const;
    bool _is_stainless;
};

//!
//! Client - stores prototype Metals to clone.
//!
class MetalShop
{
  public:
    MetalShop();
    std::shared_ptr<Metal> get_metal(std::string name, int length, int width);

  private:
    std::map<std::string, std::shared_ptr<Metal>> prototypes;
};
