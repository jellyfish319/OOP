#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <typename T>
class Queue : private List<T> {
 public:
  Queue() : List<T>() {}

  Queue(const Queue& queue) : List<T>(queue) {}

  void operator=(const Queue& queue) {
    List<T>::operator=(queue);
  }

  int size() const {
    return List<T>::size();
  }

  void Add(T elem) {
    List<T>::PushFront(elem);
  }

  T Poll() {
    T value = List<T>::PopBackReturn();
  List<T>::PopBack();
  return value;
  }

  bool IsEmpty() const {
    return List<T>::IsEmpty();
  }
};

#endif  // QUEUE_H

