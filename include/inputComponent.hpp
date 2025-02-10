#ifndef INPUTCOMPONENTS_HPP_
#define INPUTCOMPONENTS_HPP_

#include "Acomponent.hpp"

namespace nts {
class InputComponent : public AComponent {
public:
  ~InputComponent() = default;
  InputComponent() = default;

private:
    std::size_t _pin = nts::Tristate::Undefined;
};
}

#endif