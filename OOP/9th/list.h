#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <cstddef>

class List {
 public:
  List();
  List(const List& list);
  virtual ~List();
  void operator=(const List& list);
  int size() const;
  void PushBack(int elem);
  void PushFront(int elem);
  void PopBack();
  void PopFront();
  int& At(int index);
  bool IsEmpty() const;
  int PopBackReturn();
 private:
  struct Elem {
    int value;
  Elem* next;
  };
  Elem* head_;
  int size_;
};

#endif  // LIST_H
