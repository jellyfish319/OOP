#include "vector.h"

Vector::Vector(std::size_t capacity) : capacity_(capacity), size_(0) {
  elements_ = new int[capacity];
}

Vector::~Vector() {
  delete[] elements_;
}

Vector::Vector(const Vector& vector) :
capacity_(vector.capacity_), size_(vector.size_) {
  elements_ = new int[capacity_];
  for (int i = 0 ; i < size_ ; i++) {
    elements_[i] = vector.elements_[i];
  }
}

void Vector::operator=(const Vector& vector) {
  size_ = vector.size_;
  delete[] elements_;  // 기존 객체에 동적할당 된 모든 정보를 삭제
  capacity_ = vector.capacity_;
  elements_ = new int[capacity_];
  for (int i = 0 ; i < size_ ; i++) {
    elements_[i] = vector.elements_[i];
  }
}

int& Vector::operator[](const int index) {
  assert(index < size_ && "Out-of-bound");
  return elements_[index];
}

int Vector::size() const {
  return size_;
}

int Vector::capacity() const {
  return capacity_;
}

void Vector::PushBack(int elem) {
  if (capacity_ < (size_+1)) {
    capacity_ = capacity_+4;
    int* newElements_ = new int[capacity_];
    for (int i = 0 ; i < size_ ; i++) {
      newElements_[i] = elements_[i];
    }
    delete[] elements_;
    elements_ = newElements_;
  }
  elements_[size_++] = elem;
}

void Vector::PopBack() {
  assert(size_ != 0 && "Out-of-bound");
  size_--;
}

bool Vector::IsEmpty() const {
  return size_ == 0;
}
