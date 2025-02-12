#include "SpecialComponent.hpp"
#include "nts.hpp"

nts::Tristate nts::SpecialComponent::compute(std::size_t pin) {return _state;}

void nts::SpecialComponent::setPin(std::size_t pin) {_pin = pin;}

void nts::SpecialComponent::setState(nts::Tristate state) {_state = state;}