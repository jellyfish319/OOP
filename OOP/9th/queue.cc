#include "queue.h"

Queue::Queue() : List() {}

Queue::Queue(const Queue& queue) : List(queue) {}

void Queue::operator=(const Queue& queue) {
    List::operator=(queue);
}

int Queue::size() const {
  return List::size();
}

void Queue::Add(int elem) {
  List::PushFront(elem);
}

int Queue::Poll() {
  int value = List::PopBackReturn();
  List::PopBack();
  return value;
}

bool Queue::IsEmpty() const {
  return List::IsEmpty();
}
