#include "AndGate.hpp"
#include "nts.hpp"
#include <vector>

nts::Tristate nts::AndGate::compute(std::size_t pin) {
  std::vector<nts::Tristate> state = {nts::Tristate::Undefined,
                                      nts::Tristate::Undefined};

  for (size_t &i : _pins) {
    if (i == pin)
      continue;
    state.push_back(_connection[i].first->compute(_connection[i].second));
  }
  if (state[0] == nts::Tristate::True && state[1] == nts::Tristate::True)
    return nts::Tristate::True;
  if (state[0] == nts::Tristate::True || state[1] == nts::Tristate::Undefined)
    return nts::Tristate::Undefined;
  if (state[0] == nts::Tristate::Undefined || state[1] == nts::Tristate::True)
    return nts::Tristate::Undefined;
  if (state[0] == nts::Tristate::Undefined ||
      state[1] == nts::Tristate::Undefined)
    return nts::Tristate::Undefined;
  return nts::Tristate::False;
}
