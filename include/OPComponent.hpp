#ifndef OPCOMPONENTS_HPP_
#define OPCOMPONENTS_HPP_

#include "Acomponent.hpp"

namespace nts {
class OPComponent : public AComponent {
public:
  ~OPComponent() = default;
  OPComponent() = default;

private:
  std::size_t _pin = nts::Tristate::Undefined;
};
} // namespace nts

#endif
