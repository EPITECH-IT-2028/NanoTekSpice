#include "Acomponent.hpp"
#include "nts.hpp"
#include <utility>

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
                              std::size_t otherPin) {
  setPin(pin);
  _connection[pin] = std::make_pair(&other, otherPin);
};
