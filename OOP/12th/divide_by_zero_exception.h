#ifndef DIVIDE_BY_ZERO_EXCEPTION_H
#define DIVIDE_BY_ZERO_EXCEPTION_H

#include <stdexcept>

class DivideByZeroException : public std::runtime_error {
 public:
  explicit DivideByZeroException(const char* what);
};

#endif  // DIVIDE_BY_ZERO_EXCEPTION_H
