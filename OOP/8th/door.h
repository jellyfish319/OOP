#ifndef DOOR_H
#define DOOR_H

#include <string>
#include "part.h"

class Door : public Part {
 public:
  explicit Door(std::string factory_name);
  std::string GetInfo() const override;
};

#endif  // DOOR_H
