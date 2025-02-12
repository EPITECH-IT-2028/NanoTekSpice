#ifndef TRUECOMPONENTS_HPP_
#define TRUECOMPONENTS_HPP_

#include "SpecialComponent.hpp"

namespace nts {
class TrueComponent : public nts::SpecialComponent {
public:
  ~TrueComponent() = default;
  TrueComponent() {setState(nts::Tristate::False);};
};
}

#endif