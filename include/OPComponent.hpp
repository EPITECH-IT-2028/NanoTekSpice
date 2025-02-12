#ifndef OPCOMPONENTS_HPP_
#define OPCOMPONENTS_HPP_

#include "SpecialComponent.hpp"

namespace nts {
class OPComponent : public SpecialComponent {
public:
  ~OPComponent() = default;
  OPComponent() {setState(nts::Tristate::Undefined);};
};
} // namespace nts

#endif
