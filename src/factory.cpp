#include "Factory.hpp"
#include "OPComponent.hpp"
#include "clockComponent.hpp"
#include "falseComponent.hpp"
#include "inputComponent.hpp"
#include "trueComponent.hpp"
#include <memory>

std::shared_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    if (type == "true")
        return std::make_shared<nts::TrueComponent>();
    if (type == "false")
        return std::make_shared<nts::FalseComponent>();
    if (type == "output")
        return std::make_shared<nts::OPComponent>();
    if (type == "input")
        return std::make_shared<nts::InputComponent>();
    if (type == "clock")
        return std::make_shared<nts::ClockComponent>();
    return nullptr;
}
