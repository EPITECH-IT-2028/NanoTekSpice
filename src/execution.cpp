#include "OPComponent.hpp"
#include "SpecialComponent.hpp"
#include "nts.hpp"
#include <iostream>
#include <list>
#include <string>

void display(std::map<std::string, std::shared_ptr<nts::IComponent>> &components) {
  std::list<std::string> disp_input;
  std::list<std::string> disp_output;
  for (const auto &component : components) {
      std::string name = component.first;
    if (dynamic_cast<nts::OPComponent *>(component.second.get())) {
      disp_output.push_back(name);
      continue;
    }
    if (dynamic_cast<nts::SpecialComponent *>(component.second.get()))
      disp_input.push_back(name);
  }
  //std::cout << "tick: " << tick << std::endl;
  std::cout << "input(s):" << std::endl;
  for (std::string name : disp_input) {
    std::cout << "   " << name << ": ";
    nts::Tristate state = components[name]->compute(1);
    if (state == nts::False)
      std::cout << "0";
    else if (state == nts::True)
      std::cout << "1";
    else
      std::cout << "U";
    std::cout << std::endl;
  }
  std::cout << "output(s):" << std::endl;
  for (std::string name : disp_output) {
    std::cout << "   " << name << ": ";
    nts::Tristate state = components[name]->compute(1);
    if (state == nts::False)
      std::cout << "0";
    else if (state == nts::True)
      std::cout << "1";
    else
      std::cout << "U";
    std::cout << std::endl;
  }
}

void simulate(std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
  std::list<std::string> outputs;
  for (const auto &component : components) {
      std::string name = component.first;
    if (dynamic_cast<nts::OPComponent *>(component.second.get()))
      outputs.push_back(name);
  }
  for (std::string name : outputs) {
    components[name]->simulate(1);
  }
}

/*
 * This function is the loop of the program.
 * @param void
 * @return 0
 */
int nts::execute(std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
  std::string word;

  std::cout << "> ";
  while (std::getline(std::cin, word)) {
    if (word == "exit")
      break;
    if (word == "display")
      display(components);
    if (word == "simulate")
      simulate(components);
    if (word == "loop")
      continue;
    std::cout << "> ";
  }
  return 0;
}
