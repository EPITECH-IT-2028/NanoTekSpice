#include "Execute.hpp"
#include <iostream>

/*
 * This function is the loop of the program.
 * @param void
 * @return 0
 */
int nts::execute(
    std::map<std::string, std::shared_ptr<nts::IComponent>> components) {
  std::string command;
  nts::Execute exec(components);

  std::cout << "> ";
  while (std::getline(std::cin, command)) {
    if (command == "exit")
      break;
    exec.doCommand(command);
    std::cout << "> ";
  }
  return 0;
}
