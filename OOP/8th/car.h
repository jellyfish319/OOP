#ifndef CAR_H
#define CAR_H

#include <string>
#include "part.h"

class CarBuilder;

class Car{
 public:
  Car(const Car& car) = delete;
  Car& operator=(const Car& car) = delete;
  std::string GetSpec() const;
  ~Car();
 private:
  Car(Part* door, Part* wheel, Part* roof, std::string color);
  Part* door_;
  Part* wheel_;
  Part* roof_;
  std::string color_;
  friend CarBuilder;
};

#endif  // CAR_H
