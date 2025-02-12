#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "nts.hpp"
#include <functional>
#include <memory>
#include <unordered_map>

namespace nts {
class Factory {
public:
  std::shared_ptr<IComponent> createComponent(const std::string &type);

private:
  static const std::unordered_map<std::string, std::function<std::shared_ptr<IComponent>()>> _creators;

};
}

#endif