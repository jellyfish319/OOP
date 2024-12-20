#ifndef STACK_H
#define STACK_H

#include "vector.h"

template <typename T>
class Stack : private Vector<T> {
 public:
  explicit Stack(std::size_t capacity) : Vector<T>(capacity) {}

  Stack(const Stack& stack) : Vector<T>(stack) {}

  void operator=(const Stack& stack) {
    Vector<T>::operator=(stack);
  }

  int size() const {
    return Vector<T>::size();
  }

  int capacity() const {
    return Vector<T>::capacity();
  }

  void Push(T elem) {
    Vector<T>::PushBack(elem);
  }

  T Pop() {
  assert(!IsEmpty() && "Out-of-bound");
  T top = (*this)[size()-1];
  Vector<T>::PopBack();
  return top;
  }

  bool IsEmpty() const {
    return Vector<T>::IsEmpty();
  }
};

#endif  // STACK_H

