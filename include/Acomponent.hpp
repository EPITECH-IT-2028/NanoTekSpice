#ifndef ACOMPONENTS_HPP_
#define ACOMPONENTS_HPP_

#include "nts.hpp"

namespace nts {
class AComponent : public nts::IComponent {
public:
  virtual ~AComponent() = default;
  virtual void simulate(std::size_t tick);
  virtual nts::Tristate compute(std::size_t pin) = 0;
  virtual void setLink(std::size_t pin, nts::IComponent &other,
                       std::size_t otherPin);
};
}

#endif
