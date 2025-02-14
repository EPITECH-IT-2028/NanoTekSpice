#include "Gate.hpp"
#include "OutputComponent.hpp"
#include "nts.hpp"
#include <vector>
#include <iostream>

void nts::Gate::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin) {
  setPin(pin);
  _connection[pin] = std::make_pair(&other, otherPin);
};

void nts::Gate::setPin(std::size_t pin) { _pins[pin] = nts::Tristate::Undefined; }

nts::Tristate nts::Gate::compute(std::size_t pin) { return _pins[pin]; }

void nts::AndGate::simulate(std::size_t tick) {
  _connection[1].first->simulate(tick);
  _pins[1] = _connection[1].first->compute(_connection[1].second);
  _connection[2].first->simulate(tick);
  _pins[2] = _connection[2].first->compute(_connection[2].second);
  nts::Tristate input1 = compute(1);
  nts::Tristate input2 = compute(2);
  if (input1 == nts::Tristate::True && input2 == nts::Tristate::True)
    _pins[3] = nts::Tristate::True;
  else if (input1 == nts::Tristate::True &&
           input2 == nts::Tristate::Undefined)
    _pins[3] = nts::Tristate::Undefined;
  else if (input1 == nts::Tristate::Undefined &&
           input2 == nts::Tristate::True)
    _pins[3] = nts::Tristate::Undefined;
  else if (input1 == nts::Tristate::Undefined &&
           input2 == nts::Tristate::Undefined)
    _pins[3] = nts::Tristate::Undefined;
  else
    _pins[3] = nts::Tristate::False;
}

void nts::OrGate::simulate(std::size_t tick) {
  _connection[1].first->simulate(tick);
  _pins[1] = _connection[1].first->compute(_connection[1].second);
  _connection[2].first->simulate(tick);
  _pins[2] = _connection[2].first->compute(_connection[2].second);
  nts::Tristate input1 = compute(1);
  nts::Tristate input2 = compute(2);
  if (input1 == nts::Tristate::False && input2 == nts::Tristate::False)
    _pins[3] = nts::Tristate::False;
  else if (input1 == nts::Tristate::False &&
           input2 == nts::Tristate::Undefined)
    _pins[3] = nts::Tristate::Undefined;
  else if (input1 == nts::Tristate::Undefined &&
           input2 == nts::Tristate::False)
    _pins[3] = nts::Tristate::Undefined;
  else if (input1 == nts::Tristate::Undefined &&
           input2 == nts::Tristate::Undefined)
    _pins[3] = nts::Tristate::Undefined;
  else
    _pins[3] = nts::Tristate::True;
}

void nts::XorGate::simulate(std::size_t tick) {
  _connection[1].first->simulate(tick);
  _pins[1] = _connection[1].first->compute(_connection[1].second);
  _connection[2].first->simulate(tick);
  _pins[2] = _connection[2].first->compute(_connection[2].second);
  nts::Tristate input1 = compute(1);
  nts::Tristate input2 = compute(2);
  if (input1 == nts::Tristate::False && input2 == nts::Tristate::False)
    _pins[3] = nts::Tristate::False;
  else if (input1 == nts::Tristate::True && input2 == nts::Tristate::True)
    _pins[3] = nts::Tristate::False;
  else if (input1 == nts::Tristate::False &&
           input2 == nts::Tristate::True)
    _pins[3] = nts::Tristate::True;
  else if (input1 == nts::Tristate::True &&
           input2 == nts::Tristate::False)
    _pins[3] = nts::Tristate::True;
  else
    _pins[3] = nts::Tristate::Undefined;
}

void nts::NotGate::simulate(std::size_t tick) {
  _connection[1].first->simulate(tick);
  _pins[1] = _connection[1].first->compute(_connection[1].second);
  nts::Tristate input1 = compute(1);
  if (input1 == nts::Tristate::False)
    _pins[2] = nts::Tristate::True;
  else if (input1 == nts::Tristate::True)
    _pins[2] = nts::Tristate::False;
  else
    _pins[2] = nts::Tristate::Undefined;
}
