#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "nts.hpp"
#include <vector>

class Circuit {
public:
  Circuit() = default;
  ~Circuit() = default;

  void addComponent(nts::IComponent, std::string);

  void findComponent(std::string);

private:
  std::vector<std::vector<nts::IComponent>> _circuit;
};

#endif
