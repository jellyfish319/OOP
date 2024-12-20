#ifndef STACK_H
#define STACK_H

#include "vector.h"

class Stack : private Vector {
 public:
  explicit Stack(std::size_t capacity);
  Stack(const Stack& stack);
  void operator=(const Stack& stack);
  int size() const;
  int capacity() const;
  void Push(int elem);
  int Pop();
  bool IsEmpty() const;
};

#endif  // STACK_H
