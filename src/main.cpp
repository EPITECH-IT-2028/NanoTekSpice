#include "nts.hpp"

int main(int argc, char **argv) {
  if (argc != 2)
    return 84; // TODO : throw exception
  std::map<std::string, std::shared_ptr<nts::IComponent>> components;
  components = parser(argv[1]);

  return nts::execute();
}
