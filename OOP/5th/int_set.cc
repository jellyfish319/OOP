#include "int_set.h"

IntSet::IntSet(int capacity) {
  capacity_ = capacity;
  size_ = 0;
  elements_ = new int[capacity_];
}

IntSet::IntSet(const IntSet& int_set) {
  capacity_ = int_set.capacity_;
  size_ = int_set.size_;
  elements_ = new int[capacity_];

  for (int i = 0; i < size_; i++) {
    elements_[i] = int_set.elements_[i];
  }
}

IntSet::~IntSet() {
  delete[] elements_;
}

int IntSet::capacity() const {
  return capacity_;
}

int IntSet::size() const {
  return size_;
}

int* IntSet::elements() const {
  return elements_;
}

void IntSet::Add(int value) {
  for (int count=0 ; count < size_ ; count++) {
    if (elements_[count] == value) {
      return;
    }
  }
    if (size_ >= capacity_) {
      capacity_ += 4;
      int* new_elements = new int[capacity_];
        for (int i = 0; i < size_; i++) {
          new_elements[i] = elements_[i];
    }
  delete[] elements_;
  elements_ = new_elements;
  }
  elements_[size_] = value;
  size_++;
}

void IntSet::Add(const IntSet& int_set) {
  for (int i = 0; i < int_set.size_; i++) {
    bool found = false;

    for (int j = 0; j < size_; j++) {
      if (elements_[j] == int_set.elements_[i]) {
        found = true;
        break;
      }
    }

    if (!found) {
      if (size_ >= capacity_) {
        capacity_ += 4;
        int* new_elements = new int[capacity_];
        for (int i = 0; i < size_; i++) {
          new_elements[i] = elements_[i];
          }
        delete[] elements_;
        elements_ = new_elements;
        }
      elements_[size_] = int_set.elements_[i];
      size_++;
    }
  }
}


void IntSet::Map(std::function<int(int)> f) {
  for (int count = 0 ; count < size_ ; count++) {
    elements_[count] = f(elements_[count]);
  }
}

bool IntSet::ForAll(std::function<bool(int)> f) {
  for (int count = 0 ; count < size_ ; count++) {
    if (!f(elements_[count])) {
      return false;
    }
  }
  return true;
}

int IntSet::operator[](int index) {
  assert(index >= 0 && index < size_ && "Out-of-bound");
  return elements_[index];
}
