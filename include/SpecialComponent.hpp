#ifndef SPECIALCOMPONENTS_HPP_
#define SPECIALCOMPONENTS_HPP_

#include "Acomponent.hpp"

namespace nts {
class SpecialComponent : public nts::AComponent {
public:
  ~SpecialComponent() = default;
  nts::Tristate compute(std::size_t pin) override;
  void setLink(std::size_t pin, nts::IComponent &other,
                       std::size_t otherPin) override;
  void setPin(std::size_t pin) override;
  void setState(nts::Tristate state);

protected:
  std::size_t _pin;
  nts::Tristate _state;
};
} // namespace nts

#endif
