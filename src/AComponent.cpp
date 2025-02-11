#include "Acomponent.hpp"
#include "nts.hpp"
#include <memory>
#include <utility>

nts::AComponent::~AComponent() = default;

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    _conection[pin] = std::make_pair(&other, otherPin);
};