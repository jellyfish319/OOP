#ifndef WHEEL_H
#define WHEEL_H

#include <string>
#include "part.h"

class Wheel : public Part {
 public:
  explicit Wheel(std::string factory_name);
  std::string GetInfo() const override;
};

#endif  // WHEEL_H
