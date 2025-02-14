#include "Error.hpp"
#include "nts.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./nanotekspice [file]" << std::endl;
    return 84;
  }
  std::map<std::string, std::shared_ptr<nts::IComponent>> components;
  try {
    components = nts::parser(argv[1]);
    nts::execute(components);
  } catch (const nts::Error &e) {
    std::cerr << e.what() << std::endl;
    return 84;
  }
  return 0;
}
