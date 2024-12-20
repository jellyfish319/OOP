#include "list.h"

List::List() : size_(0), head_(nullptr) {}

List::List(const List& list) : size_(list.size_), head_(nullptr) {
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


List::~List() {
  while (head_ != nullptr) {
    Elem* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

void List::operator=(const List& list) {
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

int List::size() const {
  return size_;
}

int& List::At(int index) {
  assert(((index < size_) && (index >= 0)) && "Out-of-bound");
  Elem* temp = head_;
  for (int i = 0 ; i < index ; i++) {
    temp = temp->next;
  }
  return temp->value;
}

bool List::IsEmpty() const {
  return size_ == 0;
}

void List::PushBack(int elem) {
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

void List::PushFront(int elem) {
  Elem* temp = head_;
  head_ = new Elem{elem, temp};
  size_++;
}

void List::PopBack() {
  assert(size_ != 0 && "Out-of-bound");
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

void List::PopFront() {
  assert(size_ != 0 && "Out-of-bound");
  Elem* temp = head_->next;
  delete head_;
  head_ = temp;
  size_--;
}

int List::PopBackReturn() {
  assert(size_ != 0 && "Out-of-bound");
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
