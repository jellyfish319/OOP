#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <string>
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

class Person {
 public:
  explicit Person(int age) : age_(age) {}
  int age() const { return age_; }
  bool operator==(const Person& other) const {
    return age_ == other.age_;
  }
 private:
  int age_;
};

class PersonIncreasingOrder {
 public:
  int operator()(const Person& person1, Person& person2) {
    if (person1.age() > person2.age()) {
      return 1;
    } else {
      return 0;
    }
  }
};

class PersonDecreasingOrder {
 public:
  int operator()(const Person& person1, Person& person2) {
    if (person1.age() < person2.age()) {
      return 1;
    } else {
      return 0;
    }
  }
};

TEST(VectorTest, IntIncreasingOrder) {
  std::vector<int> vec = {3, 1, 5, 2, 6, 8, 4, 0};
  std::vector<int> comp = {0, 1, 2, 3, 4, 5, 6, 8};
  Sort<std::vector<int>, IntIncreasingOrder>(vec.begin(), vec.end());
  EXPECT_EQ(vec, comp);
}

TEST(VectorTest, IntDecreasingOrder) {
  std::vector<int> vec = {3, 1, 5, 2, 6, 8, 4, 0};
  std::vector<int> comp = {8, 6, 5, 4, 3, 2, 1, 0};
  Sort<std::vector<int>, IntDecreasingOrder>(vec.begin(), vec.end());
  EXPECT_EQ(vec, comp);
}


TEST(VectorTest, PersonIncreasingOrder) {
  std::vector<Person> vec =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::vector<Person> comp =
  {Person(19), Person(22), Person(23), Person(27),
  Person(31), Person(36), Person(40), Person(57)};
  Sort<std::vector<Person>, PersonIncreasingOrder>(vec.begin(), vec.end());
  EXPECT_EQ(vec, comp);
}

TEST(VectorTest, PersonDecreasingOrder) {
  std::vector<Person> vec =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::vector<Person> comp =
  {Person(57), Person(40), Person(36), Person(31),
  Person(27), Person(23), Person(22), Person(19)};
  Sort<std::vector<Person>, PersonDecreasingOrder>(vec.begin(), vec.end());
  EXPECT_EQ(vec, comp);
}

TEST(ListTest, IntIncreasingOrder) {
  std::list<int> list = {3, 1, 5, 2, 6, 8, 4, 0};
  std::list<int> comp = {0, 1, 2, 3, 4, 5, 6, 8};
  Sort<std::list<int>, IntIncreasingOrder>(list.begin(), list.end());
  EXPECT_EQ(list, comp);
}

TEST(ListTest, IntDecreasingOrder) {
  std::list<int> list = {3, 1, 5, 2, 6, 8, 4, 0};
  std::list<int> comp = {8, 6, 5, 4, 3, 2, 1, 0};
  Sort<std::list<int>, IntDecreasingOrder>(list.begin(), list.end());
  EXPECT_EQ(list, comp);
}


TEST(ListTest, PersonIncreasingOrder) {
  std::list<Person> list =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::list<Person> comp =
  {Person(19), Person(22), Person(23), Person(27),
  Person(31), Person(36), Person(40), Person(57)};
  Sort<std::list<Person>, PersonIncreasingOrder>(list.begin(), list.end());
  EXPECT_EQ(list, comp);
}

TEST(ListTest, PersonDecreasingOrder) {
  std::list<Person> list =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::list<Person> comp =
  {Person(57), Person(40), Person(36), Person(31),
  Person(27), Person(23), Person(22), Person(19)};
  Sort<std::list<Person>, PersonDecreasingOrder>(list.begin(), list.end());
  EXPECT_EQ(list, comp);
}

TEST(DequeTest, IntIncreasingOrder) {
  std::deque<int> deq = {3, 1, 5, 2, 6, 8, 4, 0};
  std::deque<int> comp = {0, 1, 2, 3, 4, 5, 6, 8};
  Sort<std::deque<int>, IntIncreasingOrder>(deq.begin(), deq.end());
  EXPECT_EQ(deq, comp);
}

TEST(DequeTest, IntDecreasingOrder) {
  std::deque<int> deq = {3, 1, 5, 2, 6, 8, 4, 0};
  std::deque<int> comp = {8, 6, 5, 4, 3, 2, 1, 0};
  Sort<std::deque<int>, IntDecreasingOrder>(deq.begin(), deq.end());
  EXPECT_EQ(deq, comp);
}


TEST(DequeTest, PersonIncreasingOrder) {
  std::deque<Person> deq =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::deque<Person> comp =
  {Person(19), Person(22), Person(23), Person(27),
  Person(31), Person(36), Person(40), Person(57)};
  Sort<std::deque<Person>, PersonIncreasingOrder>(deq.begin(), deq.end());
  EXPECT_EQ(deq, comp);
}

TEST(DequeTest, PersonDecreasingOrder) {
  std::deque<Person> deq =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::deque<Person> comp =
  {Person(57), Person(40), Person(36), Person(31),
  Person(27), Person(23), Person(22), Person(19)};
  Sort<std::deque<Person>, PersonDecreasingOrder>(deq.begin(), deq.end());
  EXPECT_EQ(deq, comp);
}

TEST(ArrayTest, IntIncreasingOrder) {
  std::array<int, 8> arr =
  {3, 1, 5, 2, 6, 8, 4, 0};
  std::array<int, 8> comp =
  {0, 1, 2, 3, 4, 5, 6, 8};
  Sort<std::array<int, 8>, IntIncreasingOrder>(arr.begin(), arr.end());
  EXPECT_EQ(arr, comp);
}

TEST(ArrayTest, IntDecreasingOrder) {
  std::array<int, 8> arr = {3, 1, 5, 2, 6, 8, 4, 0};
  std::array<int, 8> comp = {8, 6, 5, 4, 3, 2, 1, 0};
  Sort<std::array<int, 8>, IntDecreasingOrder>(arr.begin(), arr.end());
  EXPECT_EQ(arr, comp);
}


TEST(ArrayTest, PersonIncreasingOrder) {
  std::array<Person, 8> arr =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::array<Person, 8> comp =
  {Person(19), Person(22), Person(23), Person(27),
  Person(31), Person(36), Person(40), Person(57)};
  Sort<std::array<Person, 8>, PersonIncreasingOrder>(arr.begin(), arr.end());
  EXPECT_EQ(arr, comp);
}

TEST(ArrayTest, PersonDecreasingOrder) {
  std::array<Person, 8> arr =
  {Person(31), Person(23), Person(57), Person(22),
  Person(36), Person(19), Person(40), Person(27)};
  std::array<Person, 8> comp =
  {Person(57), Person(40), Person(36), Person(31),
  Person(27), Person(23), Person(22), Person(19)};
  Sort<std::array<Person, 8>, PersonDecreasingOrder>(arr.begin(), arr.end());
  EXPECT_EQ(arr, comp);
}
