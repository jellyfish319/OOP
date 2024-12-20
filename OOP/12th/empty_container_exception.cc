#include "empty_container_exception.h"

EmptyContainerException::EmptyContainerException(const char* what) :
std::runtime_error(what) {}
