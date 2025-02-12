#ifndef OPCOMPONENTS_HPP_
#define OPCOMPONENTS_HPP_

#include "SpecialComponent.hpp"

namespace nts {
class OPComponent : public SpecialComponent {
public:
  ~OPComponent() = default;
  OPComponent() {setState(nts::Tristate::Undefined);};

  void simulate(std::size_t tick) override {
    setState(_connection[_pin].first->compute(_connection[_pin].second));
  };

};
} // namespace nts

#endif
