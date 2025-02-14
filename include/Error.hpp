#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace nts {

class Error : public std::exception {
public:
  Error(std::string msg) : _msg(msg) {}

  const char *what() const noexcept override;

private:
  std::string _msg;
};

} // namespace nts

#endif // ERROR_HPP_
