#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "part.h"
#include <string>
#include "car_parts_factory.h"
#include <cassert>
#include "car.h"

class CarBuilder {
 public:
  explicit CarBuilder(const CarPartsFactory* factory);
  CarBuilder& CreateDoor();
  CarBuilder& CreateWheel();
  CarBuilder& CreateRoof();
  CarBuilder& SetColor(std::string color);
  Car* Build();
 private:
  Part* door_;
  Part* wheel_;
  Part* roof_;
  std::string color_;
  const CarPartsFactory* factory_;
};

#endif  // CAR_BUILDER_H
