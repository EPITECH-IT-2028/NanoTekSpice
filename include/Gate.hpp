#ifndef GATE_HPP_
#define GATE_HPP_

#include "Acomponent.hpp"

namespace nts {

class Gate : public nts::AComponent {
  public:
    virtual ~Gate() = default;
    
    virtual nts::Tristate compute(std::size_t pin) override;
    virtual void setPin(std::size_t pin) override;
    virtual void setLink(std::size_t pin, nts::IComponent &other,
                       std::size_t otherPin) override;
  protected:
    std::map<std::size_t, nts::Tristate> _pins;
    std::size_t _output = 0;
};

class AndGate : public nts::Gate {
public:
  ~AndGate() = default;

  void simulate(std::size_t tick) override;
};

class OrGate : public nts::Gate {
public:
  OrGate() = default;

  void simulate(std::size_t tick) override;
};

class XorGate : public nts::Gate {
public:
  XorGate() = default;

  void simulate(std::size_t tick) override;
};

} // namespace nts

#endif
