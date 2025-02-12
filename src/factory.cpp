#include "Factory.hpp"
#include "Gate.hpp"
#include "OPComponent.hpp"
#include "clockComponent.hpp"
#include "falseComponent.hpp"
#include "inputComponent.hpp"
#include "trueComponent.hpp"
#include <memory>

const std::unordered_map<std::string,
                         std::function<std::shared_ptr<nts::IComponent>()>>
    nts::Factory::_creators = {
        {"input", []() { return std::make_shared<InputComponent>(); }},
        {"output", []() { return std::make_shared<OPComponent>(); }},
        {"true", []() { return std::make_shared<TrueComponent>(); }},
        {"false", []() { return std::make_shared<FalseComponent>(); }},
        {"clock", []() { return std::make_shared<ClockComponent>(); }},
        {"and", []() { return std::make_shared<AndGate>(); }},
        {"or", []() { return std::make_shared<OrGate>(); }},
        {"xor", []() { return std::make_shared<XorGate>(); }},
};

std::shared_ptr<nts::IComponent>
nts::Factory::createComponent(const std::string &type) {
  auto component = _creators.find(type);
  if (component == _creators.end())
    return nullptr;
  return component->second();
}
