#ifndef HYUNDAI_PARTS_FACTORY_H
#define HYUNDAI_PARTS_FACTORY_H

#include "car_parts_factory.h"
#include "part.h"
#include "door.h"
#include "roof.h"
#include "wheel.h"

class HyundaiPartsFactory : public CarPartsFactory {
 public:
  static HyundaiPartsFactory* GetInstance();
  Part* CreateDoor() const override;
  Part* CreateWheel() const override;
  Part* CreateRoof() const override;
 private:
  HyundaiPartsFactory();
  static HyundaiPartsFactory* instance_;
};

#endif  // HYUNDAI_PARTS_FACTORY_H
