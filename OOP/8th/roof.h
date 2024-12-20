#ifndef ROOT_H
#define ROOT_H

#include <string>
#include "part.h"

class Roof : public Part {
 public:
  explicit Roof(std::string factory_name);
  std::string GetInfo() const override;
};

#endif  // ROOT_H
