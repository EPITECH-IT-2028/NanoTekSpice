#include "OPComponent.hpp"
#include "inputComponent.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void sort(std::vector<std::string> &list) {
  for (std::size_t i = 0; i < list.size(); i++) {
    for (std::size_t j = i + 1; j < list.size(); j++) {
      if (list[i] > list[j])
        std::swap(list[i], list[j]);
    }
  }
}

void doDisplay(std::map<std::string, std::shared_ptr<nts::IComponent>> &components) {
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
  //std::cout << "tick: " << tick << std::endl;
  std::cout << "input(s):" << std::endl;
  for (std::string name : disp_input) {
    std::cout << "   " << name << ": ";
    nts::Tristate state = components[name]->compute(1);
    if (state == nts::Tristate::Undefined)
      std::cout << "U";
    else
     std::cout << state;
    std::cout << std::endl;
  }
  std::cout << "output(s):" << std::endl;
  for (std::string name : disp_output) {
    std::cout << "   " << name << ": ";
    nts::Tristate state = components[name]->compute(1);
    if (state == nts::Tristate::Undefined)
      std::cout << "U";
    else
     std::cout << state;
    std::cout << std::endl;
  }
}

void doSimulate(std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
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

// void checkInput(std::string word, std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
//   std::stringstream s(word);
//   std::string info;
//   std::vector<std::string> inf;
//   while (std::getline(s, info, '='))
//     inf.push_back(info);
//   if ()
// }

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
    else if (word == "display")
      doDisplay(components);
    else if (word == "simulate")
      doSimulate(components);
    else if (word == "loop")
      continue;
    else
      checkInput(word, components);
    std::cout << "> ";
  }
  return 0;
}
