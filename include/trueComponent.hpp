#ifndef TRUECOMPONENTS_HPP_
#define TRUECOMPONENTS_HPP_

#include "Acomponent.hpp"

namespace nts {
class TrueComponent : public nts::AComponent {
public:
  ~TrueComponent() = default;
  TrueComponent() = default;

private:
    std::size_t _pin = nts::Tristate::True;
};
}

#endif