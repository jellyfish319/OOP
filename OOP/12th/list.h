#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <cstddef>
#include "empty_container_exception.h"
#include <stdexcept>
#include <string>

template <typename T>
class List {
 public:
  List() : size_(0), head_(nullptr) {}

  List(const List& list) : size_(list.size_), head_(nullptr) {
    if (list.head_ != nullptr) {
      head_ = new Elem{list.head_->value, nullptr};
      Elem* temp = head_;
      Elem* tempList = list.head_->next;
    while (tempList != nullptr) {
      temp->next = new Elem{tempList->value, nullptr};
      temp = temp->next;
      tempList = tempList->next;
      }
    }
  }

  virtual ~List() {
    while (head_ != nullptr) {
      Elem* temp = head_;
      head_ = head_->next;
      delete temp;
    }
  }

  void operator=(const List& list) {
    while (head_ != nullptr) {
      Elem* temp = head_;
      head_ = head_->next;
      delete temp;
    }
    if (list.head_ != nullptr) {
      head_ = new Elem{list.head_->value, nullptr};
      Elem* temp = head_;
      Elem* tempList = list.head_->next;
      while (tempList != nullptr) {
        temp->next = new Elem{tempList->value, nullptr};
        temp = temp->next;
        tempList = tempList->next;
      }
    }
    size_ = list.size_;
  }

  int size() const {
    return size_;
  }

  void PushBack(T elem) {
    if (head_ == nullptr) {
      head_ = new Elem{elem, nullptr};
    } else {
      Elem* temp = head_;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = new Elem{elem, nullptr};
    }
    size_++;
  }


  void PushFront(T elem) {
    Elem* temp = head_;
  head_ = new Elem{elem, temp};
  size_++;
  }

  void PopBack() {
    if (IsEmpty()) {
      throw EmptyContainerException("This list is empty");
    }
    if (head_->next == nullptr) {
      delete head_;
      head_ = nullptr;
    } else {
      Elem* temp = head_;
      while (temp->next->next != nullptr) {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = nullptr;
    }
    size_--;
  }

  void PopFront() {
    if (IsEmpty()) {
      throw EmptyContainerException("This list is empty");
    }
    Elem* temp = head_->next;
    delete head_;
    head_ = temp;
    size_--;
  }

  T& At(int index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("The index is " + std::to_string(index) +
                                ", but the size is " + std::to_string(size_));
    }
    Elem* temp = head_;
    for (int i = 0 ; i < index ; i++) {
      temp = temp->next;
    }
    return temp->value;
  }

  bool IsEmpty() const {
    return size_  == 0;
  }

  T PopBackReturn() {
    if (IsEmpty()) {
      throw EmptyContainerException("This list is empty");
    }
    if (head_->next == nullptr) {
        return head_->value;
      } else {
      Elem* temp = head_;
      while (temp->next != nullptr) {
        temp = temp->next;
        }
      return temp->value;
      }
  }
 private :
  struct Elem {
  T value;
  Elem* next;
  };
  Elem* head_;
  int size_;
};

#endif  // LIST_H
