#ifndef GATES_HPP_
#define GATES_HPP_

#include "Acomponent.hpp"
#include <utility>
#include <vector>

namespace nts {

class Gates : public nts::AComponent {
public:
  virtual ~Gates() = default;

  virtual nts::Tristate compute(std::size_t pin) override;
  virtual void setPin(std::size_t pin) override;
  virtual void setLink(std::size_t pin, nts::IComponent &other,
                       std::size_t otherPin) override;

protected:
  std::map<std::size_t, nts::Tristate> _pins;
  std::vector<std::size_t> _output = {3, 4, 10, 11};
};

class Gates_4081 : public nts::Gates {
public:
  ~Gates_4081() = default;

  void simulate(std::size_t tick) override;
};

class Gates_4071 : public nts::Gates {
public:
  ~Gates_4071() = default;

  void simulate(std::size_t tick) override;
};

class Gates_4030 : public nts::Gates {
public:
  ~Gates_4030() = default;

  void simulate(std::size_t tick) override;
};

class Gates_4069 : public nts::Gates {
public:
  ~Gates_4069() = default;

  void simulate(std::size_t tick) override;
};

} // namespace nts

#endif
