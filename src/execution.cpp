#include <iostream>
#include <string>

/*
 * This function is the loop of the program.
 * @param void
 * @return 0
 */
int execute() {
  std::string word;

  while (std::getline(std::cin, word)) {
    std::cout << word << std::endl;
    if (word == "exit")
      break;
    if (word == "display")
      continue;
    if (word == "simulate")
      continue;
    if (word == "loop")
      continue;
  }
  return 0;
}
