#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <memory>
#include <map>

namespace nts {
enum Tristate { Undefined = (-true), True = true, False = false };

class IComponent {
public:
  virtual ~IComponent() = default;
  virtual void simulate(std::size_t tick) = 0;
  virtual nts::Tristate compute(std::size_t pin) = 0;
  virtual void setLink(std::size_t pin, nts::IComponent &other,
                       std::size_t otherPin) = 0;
};

// Functions definitions

int execute(std::map<std::string, std::shared_ptr<nts::IComponent>> components);
std::map<std::string, std::shared_ptr<nts::IComponent>> parser(const std::string &path);

} // namespace nts


#endif
