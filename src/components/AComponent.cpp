#include "Acomponent.hpp"
#include "nts.hpp"
#include <memory>
#include <utility>

nts::AComponent::~AComponent() = default;

void nts::AComponent::setPin(std::size_t pin) {
    // for (std::size_t tmp : _pins) {
    //     if (tmp == 0)
    //         tmp = pin;
    // }
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    setPin(pin);
    _conection[pin] = std::make_pair(&other, otherPin);
};