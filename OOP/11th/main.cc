#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include "sort.h"

class IntIncreasingOrder {
 public:
  int operator()(const int& x, const int& y) {
    if (x > y) {
      return 1;
    } else {
      return 0;
    }
  }
};

class IntDecreasingOrder {
 public:
  int operator()(const int& x, const int& y) {
    if (x < y) {
      return 1;
    } else {
      return 0;
    }
  }
};

template <typename T, typename N>
void SortAndPrint(T* container) {
  for (int n : *container) {
    std::cout << n << ' ';
  }
  std::cout << "-> ";

  Sort<T, N>(container->begin(), container->end());

  for (int n : *container) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::array<int, 8> arr = {3, 1, 5, 2, 6, 8, 4, 0};
  std::vector<int> vec = {3, 1, 5, 2, 6, 8, 4, 0};
  std::list<int> lst = {3, 1, 5, 2, 6, 7, 4, 0};

  SortAndPrint<std::array<int, 8>, IntIncreasingOrder>(&arr);
  SortAndPrint<std::array<int, 8>, IntDecreasingOrder>(&arr);
  SortAndPrint<std::vector<int>, IntIncreasingOrder>(&vec);
  SortAndPrint<std::vector<int>, IntDecreasingOrder>(&vec);
  SortAndPrint<std::list<int>, IntIncreasingOrder>(&lst);
  SortAndPrint<std::list<int>, IntDecreasingOrder>(&lst);
  return 0;
}

