#ifndef CAR_PARTS_FACTORY_H
#define CAR_PARTS_FACTORY_H

#include "part.h"

class CarPartsFactory {
 public:
  virtual Part* CreateDoor() const = 0;
  virtual Part* CreateWheel() const = 0;
  virtual Part* CreateRoof() const = 0;
};

#endif  // CAR_PARTS_FACTORY_H
