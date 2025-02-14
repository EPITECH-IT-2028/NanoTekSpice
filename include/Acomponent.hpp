#ifndef ACOMPONENTS_HPP_
#define ACOMPONENTS_HPP_

#include "nts.hpp"

namespace nts {
class AComponent : public nts::IComponent {
public:
  ~AComponent() = default;

  virtual void setPin(std::size_t pin) = 0;

protected:
  std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>> _connection;
};

} // namespace nts

#endif
