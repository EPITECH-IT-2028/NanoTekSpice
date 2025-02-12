#ifndef CLOCKCOMPONENTS_HPP_
#define CLOCKCOMPONENTS_HPP_

#include "SpecialComponent.hpp"

namespace nts {
class ClockComponent : public nts::SpecialComponent {
public:
  ~ClockComponent() = default;
  ClockComponent() = default;
};
}

#endif