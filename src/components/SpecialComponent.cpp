#include "SpecialComponent.hpp"

nts::Tristate nts::SpecialComponent::compute(std::size_t pin) {
  (void)pin;

  return _state;
}

void nts::SpecialComponent::simulate(std::size_t tick) {
  (void)tick;

  _state = _lastState;
  compute(_pin);
}

void nts::SpecialComponent::setPin(std::size_t pin) { _pin = pin; }

void nts::SpecialComponent::setLink(std::size_t pin, nts::IComponent &other,
                                    std::size_t otherPin) {
  setPin(pin);
  _connection[pin] = std::make_pair(&other, otherPin);
};

void nts::SpecialComponent::setState(nts::Tristate state) { _state = state; }

void nts::SpecialComponent::setLastState(nts::Tristate state) {
  _lastState = state;
}
