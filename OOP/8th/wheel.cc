#include <string>
#include "wheel.h"

Wheel::Wheel(std::string factory_name) : Part(factory_name) {}

std::string Wheel::GetInfo() const {
  return "[" + factory_name() + "] Wheel";
}

