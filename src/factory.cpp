#include "Factory.hpp"
#include "OPComponent.hpp"
#include "clockComponent.hpp"
#include "falseComponent.hpp"
#include "inputComponent.hpp"
#include "nts.hpp"
#include "trueComponent.hpp"
#include <memory>
#include <string>

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    if (type == "true")
        return std::make_unique<nts::TrueComponent>();
    if (type == "false")
        return std::make_unique<nts::FalseComponent>();
    if (type == "output")
        return std::make_unique<nts::OPComponent>();
    if (type == "input")
        return std::make_unique<nts::InputComponent>();
    if (type == "clock")
        return std::make_unique<nts::ClockComponent>();
    return nullptr;
}
