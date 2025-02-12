#ifndef AND_HPP_
#define AND_HPP_

#include "Acomponent.hpp"

namespace nts {

class OrGate : public nts::AComponent {
public:
  OrGate() = default;

  nts::Tristate compute(std::size_t pin) override;

private:
  std::vector<std::size_t> _pins = {0, 0, 0};
};

} // namespace nts
#endif
