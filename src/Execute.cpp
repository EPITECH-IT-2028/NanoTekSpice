#include "Execute.hpp"
#include "OPComponent.hpp"
#include "inputComponent.hpp"
#include "nts.hpp"
#include <cstring>
#include <iostream>

static void sort(std::vector<std::string> &list) {
  for (std::size_t i = 0; i < list.size(); i++) {
    for (std::size_t j = i + 1; j < list.size(); j++) {
      if (list[i] > list[j])
        std::swap(list[i], list[j]);
    }
  }
}

static void write(std::vector<std::string> display, std::string name,
                  auto &components) {
  std::cout << name << std::endl;
  for (std::string name : display) {
    std::cout << "  " << name << ": ";
    nts::Tristate state = components[name]->compute(1);
    if (state == nts::Tristate::Undefined)
      std::cout << "U";
    else
      std::cout << state;
    std::cout << std::endl;
  }
}

void nts::Execute::display() {
  std::vector<std::string> disp_input;
  std::vector<std::string> disp_output;

  for (const auto &component : _components) {
    std::string name = component.first;
    if (dynamic_cast<nts::OPComponent *>(component.second.get())) {
      disp_output.push_back(name);
      continue;
    }
    if (dynamic_cast<nts::SpecialComponent *>(component.second.get()))
      disp_input.push_back(name);
  }
  sort(disp_input);
  sort(disp_output);
  std::cout << "tick: " << _tick << std::endl;
  write(disp_input, "input(s):", _components);
  write(disp_output, "output(s):", _components);
}

void nts::Execute::simulate() {
  std::vector<std::string> outputs;
  for (const auto &component : _components) {
    std::string name = component.first;
    if (dynamic_cast<nts::OPComponent *>(component.second.get()))
      outputs.push_back(name);
  }
  for (std::string name : outputs)
    _components[name]->simulate(_tick);
  _tick++;
}

void nts::Execute::loop() {
  while (true)
    simulate();
}

static void setComponentState(std::string word, const auto &component) {
  std::shared_ptr<nts::InputComponent> inputComponent =
      std::static_pointer_cast<nts::InputComponent>(component.second);
  int number = 0;
  if (word.back() == 'U')
    return inputComponent->setState(nts::Tristate::Undefined);

  try {
    number = std::stol(&word.back());
  } catch (std::exception &e) {
    return; // TODO : throw exception
  }
  if (number == 0)
    inputComponent->setState(nts::Tristate::False);
  else if (number == 1)
    inputComponent->setState(nts::Tristate::True);
  else
    return; // TODO : throw exception
}

void nts::Execute::operatorOverload(std::string word) {
  for (const auto &component : _components) {
    std::string str = component.first;
    if (word.find(str) != std::string::npos) {
      setComponentState(word, component);
    }
  }
}

void nts::Execute::doCommand(const std::string &command) {
  auto res = _command.find(command);
  if (res == _command.end())
    return operatorOverload(command);
  (res->second)();
}
