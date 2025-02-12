#include "Gate.hpp"
#include "nts.hpp"
#include <vector>

nts::Tristate nts::AndGate::compute(std::size_t pin) {
  std::vector<nts::Tristate> state;

  for (size_t &i : _pins) {
    if (i == pin)
      continue;
    state.push_back(_connection[i].first->compute(_connection[i].second));
  }
  if (state[0] == nts::Tristate::True && state[1] == nts::Tristate::True)
    return nts::Tristate::True;
  if (state[0] == nts::Tristate::True && state[1] == nts::Tristate::Undefined)
    return nts::Tristate::Undefined;
  if (state[0] == nts::Tristate::Undefined && state[1] == nts::Tristate::True)
    return nts::Tristate::Undefined;
  if (state[0] == nts::Tristate::Undefined &&
      state[1] == nts::Tristate::Undefined)
    return nts::Tristate::Undefined;
  return nts::Tristate::False;
}

void nts::AndGate::setPin(std::size_t pin) {
  for (std::size_t i = 0; i < _pins.size(); i++) {
    if (_pins[i] == 0) {
      _pins[i] = pin;
      return;
    }
  }
}

nts::Tristate nts::OrGate::compute(std::size_t pin) {
  std::vector<nts::Tristate> state;

  for (size_t &i : _pins) {
    if (i == pin)
      continue;
    state.push_back(_connection[i].first->compute(_connection[i].second));
  }
  if (state[0] == nts::Tristate::False && state[1] == nts::Tristate::False)
    return nts::Tristate::False;
  if (state[0] == nts::Tristate::False && state[1] == nts::Tristate::Undefined)
    return nts::Tristate::Undefined;
  if (state[0] == nts::Tristate::Undefined && state[1] == nts::Tristate::False)
    return nts::Tristate::Undefined;
  if (state[0] == nts::Tristate::Undefined &&
      state[1] == nts::Tristate::Undefined)
    return nts::Tristate::Undefined;
  return nts::Tristate::True;
}

void nts::OrGate::setPin(std::size_t pin) {
  for (std::size_t i = 0; i < _pins.size(); i++) {
    if (_pins[i] == 0) {
      _pins[i] = pin;
      return;
    }
  }
}

nts::Tristate nts::XorGate::compute(std::size_t pin) {
  std::vector<nts::Tristate> state;

  for (size_t &i : _pins) {
    if (i == pin)
      continue;
    state.push_back(_connection[i].first->compute(_connection[i].second));
  }
  if (state[0] == nts::Tristate::False && state[1] == nts::Tristate::False)
    return nts::Tristate::False;
  if (state[0] == nts::Tristate::True && state[1] == nts::Tristate::True)
    return nts::Tristate::False;
  if (state[0] == nts::Tristate::False && state[1] == nts::Tristate::True)
    return nts::Tristate::True;
  if (state[0] == nts::Tristate::True && state[1] == nts::Tristate::False)
    return nts::Tristate::True;
  return nts::Tristate::Undefined;
}

void nts::XorGate::setPin(std::size_t pin) {
  for (std::size_t i = 0; i < _pins.size(); i++) {
    if (_pins[i] == 0) {
      _pins[i] = pin;
      return;
    }
  }
}
