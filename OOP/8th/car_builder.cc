#include "car_builder.h"

CarBuilder::CarBuilder(const CarPartsFactory* factory) :
factory_(factory), door_(nullptr), roof_(nullptr), wheel_(nullptr) {}

CarBuilder& CarBuilder::CreateDoor() {
  assert(door_ == nullptr && "Duplicated Parts retain : Door");
  this->door_ = factory_->CreateDoor();
  return *this;
}

CarBuilder& CarBuilder::CreateRoof() {
  assert(roof_ == nullptr && "Duplicated Parts retain : Roof");
  this->roof_ = factory_->CreateRoof();
  return *this;
}

CarBuilder& CarBuilder::CreateWheel() {
  assert(wheel_ == nullptr && "Duplicated Parts retain : Wheel");
  this->wheel_ = factory_->CreateWheel();
  return *this;
}

CarBuilder& CarBuilder::SetColor(std::string color) {
  this->color_ = color;
  return *this;
}

Car* CarBuilder::Build() {
  Car* car =  new Car(door_, wheel_, roof_, color_);
  door_ = nullptr;
  wheel_ = nullptr;
  roof_ = nullptr;
  color_ = "";

  return car;
}
