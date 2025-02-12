#ifndef SPECIALCOMPONENTS_HPP_
#define SPECIALCOMPONENTS_HPP_

#include "Acomponent.hpp"
#include "nts.hpp"
#include <cstddef>
#include <map>
#include <memory>
#include <utility>

namespace nts {
class SpecialComponent : public nts::AComponent {
public:
  ~SpecialComponent() = default;
  nts::Tristate compute(std::size_t pin) override;
  void setPin(std::size_t pin) override;
  void setState(nts::Tristate state);

private:
    std::size_t _pin;
    nts::Tristate _state;
};
} // namespace nts

#endif
 