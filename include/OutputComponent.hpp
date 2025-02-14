#ifndef OUTPUTCOMPONENTS_HPP_
#define OUTPUTCOMPONENTS_HPP_

#include "SpecialComponent.hpp"

namespace nts {
class OutputComponent : public SpecialComponent {
public:
  ~OutputComponent() = default;
  OutputComponent() { setState(nts::Tristate::Undefined); };

  void simulate(std::size_t tick) override {
    auto &other = _connection.begin()->second;
    other.first->simulate(tick);
    setState(other.first->compute(other.second));
  };
};
} // namespace nts

#endif
