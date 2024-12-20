#include "car.h"

std::string Car::GetSpec() const {
  std::string result = "";
  if (door_ != nullptr) {
    result.append(door_->GetInfo());
    result.append(", ");
  }

  if (wheel_ != nullptr) {
    result.append(wheel_->GetInfo());
    result.append(", ");
  }

  if (roof_ != nullptr) {
    result.append(roof_->GetInfo());
    result.append(", ");
  }

  result.append(color_);
  return result;
}

Car::~Car() {
  delete door_;
  delete wheel_;
  delete roof_;
}

Car::Car(Part* door, Part* wheel, Part* roof, std::string color) :
door_(door), wheel_(wheel), roof_(roof), color_(color) {}
