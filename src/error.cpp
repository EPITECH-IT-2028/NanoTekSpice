#include "Error.hpp"

const char *nts::Error::what() const noexcept { return _msg.c_str(); }
