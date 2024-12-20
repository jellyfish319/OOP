#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <cassert>
#include "empty_container_exception.h"
#include <stdexcept>
#include <string>

template <typename T>
class Vector {
 public:
  explicit Vector(std::size_t capacity) : capacity_(capacity), size_(0) {
  elements_ = new T[capacity];
  }

  Vector(const Vector& vector) :
  capacity_(vector.capacity_), size_(vector.size_) {
  elements_ = new T[capacity_];
  for (int i = 0 ; i < size_ ; i++) {
    elements_[i] = vector.elements_[i];
    }
  }

  virtual ~Vector() {
    delete[] elements_;
  }

  void operator=(const Vector& vector) {
    size_ = vector.size_;
    delete[] elements_;  // 기존 객체에 동적할당 된 모든 정보를 삭제
    capacity_ = vector.capacity_;
    elements_ = new T[capacity_];
    for (int i = 0 ; i < size_ ; i++) {
      elements_[i] = vector.elements_[i];
    }
  }

  T& operator[](const int index) {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("The index is " + std::to_string(index) +
      ", but the size is " + std::to_string(size_));
    }
    return elements_[index];
  }

  int size() const {
    return size_;
  }

  int capacity() const {
    return capacity_;
  }

  void PushBack(T elem) {
    if (capacity_ < (size_+1)) {
      capacity_ = capacity_+4;
      T* newElements_ = new T[capacity_];
      for (int i = 0 ; i < size_ ; i++) {
        newElements_[i] = elements_[i];
      }
      delete[] elements_;
      elements_ = newElements_;
    }
    elements_[size_++] = elem;
  }

  void PopBack() {
    if (IsEmpty()) {
      throw EmptyContainerException("This vector is empty");
    }
    size_--;
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

 private:
  T* elements_;
  int capacity_;
  int size_;
};

#endif  // VECTOR_H

