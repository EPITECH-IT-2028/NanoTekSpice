#include "OPComponent.hpp"
#include "inputComponent.hpp"
#include "nts.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static void sort(std::vector<std::string> &list) {
  for (std::size_t i = 0; i < list.size(); i++) {
    for (std::size_t j = i + 1; j < list.size(); j++) {
      if (list[i] > list[j])
        std::swap(list[i], list[j]);
    }
  }
}

static void display(std::vector<std::string> display, std::string name,
                    auto &components) {
  std::cout << name << std::endl;
  for (std::string name : display) {
    std::cout << "   " << name << ": ";
    nts::Tristate state = components[name]->compute(1);
    if (state == nts::Tristate::Undefined)
      std::cout << "U";
    else
      std::cout << state;
    std::cout << std::endl;
  }
}

static void
doDisplay(std::map<std::string, std::shared_ptr<nts::IComponent>> &components) {
  std::vector<std::string> disp_input;
  std::vector<std::string> disp_output;

  for (const auto &component : components) {
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
  // std::cout << "tick: " << tick << std::endl;
  display(disp_input, "input(s):", components);
  display(disp_output, "output(s):", components);
}

static void
doSimulate(std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
  std::vector<std::string> outputs;
  for (const auto &component : components) {
    std::string name = component.first;
    if (dynamic_cast<nts::OPComponent *>(component.second.get()))
      outputs.push_back(name);
  }
  for (std::string name : outputs) {
    components[name]->simulate(1);
  }
}

void operatorOverload(
    std::map<std::string, std::shared_ptr<nts::IComponent>> components,
    std::string word) {
  for (const auto &component : components) {
    std::string str = component.first;
    if (word.find(str) != std::string::npos) {
      std::shared_ptr<nts::InputComponent> inputComponent =
          std::static_pointer_cast<nts::InputComponent>(component.second);
      std::string tmp;
      std::stringstream str(word);
      std::getline(str, tmp, '=');
      int a = std::stol(tmp);
      if (a == 0)
        inputComponent->setState(nts::Tristate::False);
      else if (a == 1)
        inputComponent->setState(nts::Tristate::True);
      else
        inputComponent->setState(nts::Tristate::Undefined);
    }
  }
}

/*
 * This function is the loop of the program.
 * @param void
 * @return 0
 */
int nts::execute(
    std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
  std::string word;

  std::cout << "> ";
  while (std::getline(std::cin, word)) {
    if (word == "exit")
      break;
    else if (word == "display")
      doDisplay(components);
    else if (word == "simulate")
      doSimulate(components);
    else if (word == "loop")
      continue;
    else
      operatorOverload(components, word);
    std::cout << "> ";
  }
  return 0;
}
