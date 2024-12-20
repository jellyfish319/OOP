#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

class Queue : private List {
 public:
  Queue();
  Queue(const Queue& queue);
  void operator=(const Queue& queue);
  int size() const;
  void Add(int elem);
  int Poll();
  bool IsEmpty() const;
};

#endif  // QUEUE_H
