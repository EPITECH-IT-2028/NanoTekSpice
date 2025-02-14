#include "Gates.hpp"
#include "Gate.hpp"
#include "OutputComponent.hpp"
#include "nts.hpp"
#include <utility>
#include <vector>
#include <iostream>

void nts::Gates::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin) {
  setPin(pin);
  _connection[pin] = std::make_pair(&other, otherPin);
};

void nts::Gates::setPin(std::size_t pin) { _pins[pin] = Undefined; }

nts::Tristate nts::Gates::compute(std::size_t pin) { return _pins[pin]; }

void nts::Gates_4081::simulate(std::size_t tick) {
  for (auto output : _output) {
    std::vector<std::size_t> input;
    if (output == 3)
        input = {1 ,2};
    if (output == 4)
        input = {5 ,6};
    if (output == 10)
        input = {8 ,9};
    if (output == 11)
        input = {12 ,13};
    nts::AndGate gate;
    gate.setLink(3, *_connection[output].first, _connection[output].second);
    gate.setLink(2, *_connection[input[0]].first, _connection[input[0]].second);
    gate.setLink(1, *_connection[input[1]].first, _connection[input[1]].second);
    gate.simulate(tick);
    _pins[output] = gate.compute(3);
    }
}

void nts::Gates_4071::simulate(std::size_t tick) {
  for (auto output : _output) {
    std::vector<std::size_t> input;
    if (output == 3)
        input = {1 ,2};
    if (output == 4)
        input = {5 ,6};
    if (output == 10)
        input = {8 ,9};
    if (output == 11)
        input = {12 ,13};
    nts::OrGate gate;
    gate.setLink(3, *_connection[output].first, _connection[output].second);
    gate.setLink(2, *_connection[input[0]].first, _connection[input[0]].second);
    gate.setLink(1, *_connection[input[1]].first, _connection[input[1]].second);
    gate.simulate(tick);
    _pins[output] = gate.compute(3);
    }
}

void nts::Gates_4030::simulate(std::size_t tick) {
  for (auto output : _output) {
    std::vector<std::size_t> input;
    if (output == 3)
        input = {1 ,2};
    if (output == 4)
        input = {5 ,6};
    if (output == 10)
        input = {8 ,9};
    if (output == 11)
        input = {12 ,13};
    nts::XorGate gate;
    gate.setLink(3, *_connection[output].first, _connection[output].second);
    gate.setLink(2, *_connection[input[0]].first, _connection[input[0]].second);
    gate.setLink(1, *_connection[input[1]].first, _connection[input[1]].second);
    gate.simulate(tick);
    _pins[output] = gate.compute(3);
    }
}

void nts::Gates_4069::simulate(std::size_t tick) {
  for (auto [pin, state] : _pins) {
    if (pin % 2 != 0)
      continue;
    nts::NotGate gate;
    if (pin < 7) {
      gate.setLink(2, *_connection[pin].first, _connection[pin].second);
      gate.setLink(1, *_connection[pin - 1].first, _connection[pin - 1].second);
      gate.simulate(tick);
      _pins[pin] = gate.compute(2);
    } else {
      gate.setLink(2, *_connection[pin].first, _connection[pin].second);
      gate.setLink(1, *_connection[pin + 1].first, _connection[pin + 1].second);
      gate.simulate(tick);
      _pins[pin] = gate.compute(2);
    }
    }
}