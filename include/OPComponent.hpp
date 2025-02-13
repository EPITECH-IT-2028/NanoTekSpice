#ifndef OPCOMPONENTS_HPP_
#define OPCOMPONENTS_HPP_

#include "SpecialComponent.hpp"

namespace nts {
class OPComponent : public SpecialComponent {
public:
  ~OPComponent() = default;
  OPComponent() {setState(nts::Tristate::Undefined);};

  void simulate(std::size_t tick) override {
    auto &other = _connection.begin()->second;
    other.first->simulate(tick);
    setState(other.first->compute(other.second));
  };
};
} // namespace nts

#endif
