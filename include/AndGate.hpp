#ifndef AND_HPP_
#define AND_HPP_

#include "Acomponent.hpp"
#include <vector>

namespace nts {

class AndGate : public nts::AComponent {
public:
  AndGate() = default;

  ~AndGate() = default;

  nts::Tristate compute(std::size_t pin) override;
  void setPin(std::size_t pin) override;

private:
  std::vector<std::size_t> _pins = {0, 0, 0};
};

} // namespace nts
#endif
