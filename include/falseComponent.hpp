#ifndef FALSECOMPONENTS_HPP_
#define FALSECOMPONENTS_HPP_

#include "Acomponent.hpp"

namespace nts {
class FalseComponent : public AComponent {
public:
  ~FalseComponent() = default;
  FalseComponent() = default;

private:
    std::size_t _pin = nts::Tristate::False;
};
}

#endif