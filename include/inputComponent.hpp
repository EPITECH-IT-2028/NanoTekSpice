#ifndef INPUTCOMPONENTS_HPP_
#define INPUTCOMPONENTS_HPP_

#include "SpecialComponent.hpp"
#include "nts.hpp"

namespace nts {
class InputComponent : public SpecialComponent {
public:
  ~InputComponent() = default;
  InputComponent() { setState(nts::Tristate::Undefined); };
};
} // namespace nts

#endif
