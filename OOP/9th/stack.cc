#include "stack.h"

Stack::Stack(std::size_t capacity) : Vector(capacity) {}

Stack::Stack(const Stack& stack) : Vector(stack) {}

void Stack::operator=(const Stack& stack) {
  Vector::operator=(stack);
}

int Stack::size() const {
  return Vector::size();
}

int Stack::capacity() const {
  return Vector::capacity();
}

bool Stack::IsEmpty() const {
  return Vector::IsEmpty();
}

void Stack::Push(int elem) {
  PushBack(elem);
}

int Stack::Pop() {
  assert(!IsEmpty() && "Out-of-bound");
  int top = (*this)[size()-1];
  PopBack();
  return top;
}
