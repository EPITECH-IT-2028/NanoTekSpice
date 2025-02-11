#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "nts.hpp"
#include <memory>

namespace nts {
class Factory {
public:
  std::shared_ptr<nts::IComponent> createComponent(const std::string &type);
};
}

#endif