#ifndef SPECIALCOMPONENTS_HPP_
#define SPECIALCOMPONENTS_HPP_

#include "Acomponent.hpp"
#include "nts.hpp"

namespace nts {
class SpecialComponent : public nts::AComponent {
public:
  ~SpecialComponent() = default;

  nts::Tristate compute(std::size_t pin) override;
  void setLink(std::size_t pin, nts::IComponent &other,
               std::size_t otherPin) override;
  void setPin(std::size_t pin) override;
  void simulate(std::size_t tick) override;
  void setState(nts::Tristate state);
  void setLastState(nts::Tristate state);

protected:
  std::size_t _pin;
  nts::Tristate _state;
  nts::Tristate _lastState = nts::Tristate::Undefined;
};
} // namespace nts

#endif
