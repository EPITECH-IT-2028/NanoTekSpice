#ifndef CLOCKCOMPONENTS_HPP_
#define CLOCKCOMPONENTS_HPP_

#include "Acomponent.hpp"

namespace nts {
class ClockComponent : public AComponent {
public:
  ~ClockComponent() = default;
  ClockComponent() = default;

private:
    std::size_t _pin = nts::Tristate::Undefined;
};
}

#endif