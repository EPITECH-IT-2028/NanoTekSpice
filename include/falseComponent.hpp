#ifndef FALSECOMPONENTS_HPP_
#define FALSECOMPONENTS_HPP_

#include "Acomponent.hpp"
#include "SpecialComponent.hpp"
#include "nts.hpp"

namespace nts {
class FalseComponent : public nts::SpecialComponent {
public:
  ~FalseComponent() = default;
  FalseComponent() {setState(nts::Tristate::False);};
};
}

#endif