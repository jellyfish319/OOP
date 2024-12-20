#ifndef EMPTY_CONTAINER_EXCEPTION_H
#define EMPTY_CONTAINER_EXCEPTION_H

#include <stdexcept>

class EmptyContainerException : public std::runtime_error {
 public:
  explicit EmptyContainerException(const char* what);
};

#endif  // EMPTY_CONTAINER_EXCEPTION_H
