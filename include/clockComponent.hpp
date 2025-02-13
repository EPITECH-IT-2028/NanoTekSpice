#ifndef CLOCKCOMPONENTS_HPP_
#define CLOCKCOMPONENTS_HPP_

#include "SpecialComponent.hpp"
#include "nts.hpp"

namespace nts {
class ClockComponent : public nts::SpecialComponent {
public:
  ~ClockComponent() = default;
  ClockComponent() {setState(nts::Tristate::Undefined);};

   void simulate(std::size_t tick) override {
    (void)tick;
    if (_state == nts::Tristate::True)
      _state = nts::Tristate::False;
    else
      _state = nts::Tristate::False;
  };
};
} // namespace nts

#endif
