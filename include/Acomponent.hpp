#ifndef ACOMPONENTS_HPP_
#define ACOMPONENTS_HPP_

#include "nts.hpp"
#include <map>
#include <utility>

namespace nts {
class AComponent : public nts::IComponent {
public:
  virtual ~AComponent();
  virtual void simulate(std::size_t tick) override;
  virtual nts::Tristate compute(std::size_t pin) override;
  virtual void setLink(std::size_t pin, nts::IComponent &other,
                       std::size_t otherPin) override;

protected:
  std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>> _connection;

private:
  nts::Tristate _pins;
  std::size_t _tick = 0;
};
} // namespace nts

#endif
