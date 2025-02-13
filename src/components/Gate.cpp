#include "Gate.hpp"
#include "OPComponent.hpp"
#include <vector>

void nts::Gate::setLink(std::size_t pin, nts::IComponent &other,
                              std::size_t otherPin) {
  if (dynamic_cast<nts::OPComponent *>(&other))
    _output = pin;
  setPin(pin);
  _connection[pin] = std::make_pair(&other, otherPin);
};

void nts::Gate::setPin(std::size_t pin) {
      _pins[pin] = Undefined;
}

nts::Tristate nts::Gate::compute(std::size_t pin) {return _pins[pin];}

void nts::AndGate::simulate(std::size_t tick) {
  for (auto &[pin, other] : _connection) {
    if (pin != _output) {
      other.first->simulate(tick);
      _pins[pin] = other.first->compute(other.second);
    }
  }
  std::vector<nts::Tristate> states;
  for (auto &[pin, state] : _pins) {
    if (pin != _output)
      states.push_back(compute(pin));
  }
  if (states[0] == nts::Tristate::True && states[1] == nts::Tristate::True)
    _pins[_output] = nts::Tristate::True;
  else if (states[0] == nts::Tristate::True && states[1] == nts::Tristate::Undefined)
    _pins[_output] = nts::Tristate::Undefined;
  else if (states[0] == nts::Tristate::Undefined && states[1] == nts::Tristate::True)
    _pins[_output] = nts::Tristate::Undefined;
  else if (states[0] == nts::Tristate::Undefined && states[1] == nts::Tristate::Undefined)
    _pins[_output] = nts::Tristate::Undefined;
  else
    _pins[_output] = nts::Tristate::False;
}

void nts::OrGate::simulate(std::size_t tick) {
  for (auto &[pin, other] : _connection) {
    if (pin != _output) {
      other.first->simulate(tick);
      _pins[pin] = other.first->compute(other.second);
    }
  }
  std::vector<nts::Tristate> states;
  for (auto &[pin, state] : _pins) {
    if (pin != _output)
      states.push_back(compute(pin));
  }
  if (states[0] == nts::Tristate::False && states[1] == nts::Tristate::False)
    _pins[_output] = nts::Tristate::False;
  else if (states[0] == nts::Tristate::False && states[1] == nts::Tristate::Undefined)
    _pins[_output] = nts::Tristate::Undefined;
  else if (states[0] == nts::Tristate::Undefined && states[1] == nts::Tristate::False)
    _pins[_output] = nts::Tristate::Undefined;
  else if (states[0] == nts::Tristate::Undefined && states[1] == nts::Tristate::Undefined)
    _pins[_output] = nts::Tristate::Undefined;
  else
    _pins[_output] = nts::Tristate::True;
}

void nts::XorGate::simulate(std::size_t tick) {
  for (auto &[pin, other] : _connection) {
    if (pin != _output) {
      other.first->simulate(tick);
      _pins[pin] = other.first->compute(other.second);
    }
  }
  std::vector<nts::Tristate> states;
  for (auto &[pin, state] : _pins) {
    if (pin != _output)
      states.push_back(compute(pin));
  }
  if (states[0] == nts::Tristate::False && states[1] == nts::Tristate::False)
    _pins[_output] = nts::Tristate::False;
  else if (states[0] == nts::Tristate::True && states[1] == nts::Tristate::True)
    _pins[_output] = nts::Tristate::False;
  else if (states[0] == nts::Tristate::False && states[1] == nts::Tristate::True)
    _pins[_output] = nts::Tristate::True;
  else if (states[0] == nts::Tristate::True && states[1] == nts::Tristate::False)
    _pins[_output] = nts::Tristate::True;
  else
    _pins[_output] = nts::Tristate::Undefined;
}
