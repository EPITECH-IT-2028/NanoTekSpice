#ifndef EXECUTE_HPP_
#define EXECUTE_HPP_

#include "nts.hpp"
#include <functional>
#include <memory>
#include <unordered_map>

namespace nts {
class Execute {
public:
  ~Execute() = default;
  Execute(std::map<std::string, std::shared_ptr<nts::IComponent>> components) : _components(components) {};
  void doCommand(const std::string &command);
  void display();
  void simulate();
  void loop();

private:
  std::size_t _tick = 0;
  std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
  const std::unordered_map<std::string, std::function<void()>> _command = {
        {"display", [this]() {this->display();}},
        {"simulate", [this]() {this->simulate();}},
        {"loop", [this]() {this->loop();}},
};;
};
}

#endif