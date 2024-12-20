#include <gtest/gtest.h>
#include "vector.h"
#include "stack.h"
#include "list.h"
#include "queue.h"

// Vector 테스트
TEST(VectorTest, PushBackAndAccess) {
  Vector v(5);
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, SizeAfterPushBack) {
  Vector v(5);
  v.PushBack(1);
  EXPECT_EQ(v.size(), 1);
  v.PushBack(2);
  EXPECT_EQ(v.size(), 2);
}

TEST(VectorTest, Capacity) {
  Vector v(5);
  EXPECT_EQ(v.capacity(), 5);
  v.PushBack(1);
  EXPECT_EQ(v.capacity(), 5);
}

TEST(VectorTest, PopBackReducesSize) {
  Vector v(5);
  v.PushBack(1);
  v.PushBack(2);
  v.PopBack();
  EXPECT_EQ(v.size(), 1);
}

TEST(VectorTest, OutOfBoundsAccess) {
  Vector v(5);
  v.PushBack(1);
  ASSERT_DEATH(v[5], "Out-of-bound");
}  // 범위를 벗어난 접근이므로 에러가 발생해야 함

// Stack 테스트
TEST(StackTest, PushAndPopOrder) {
  Stack s(5);
  s.Push(10);
  s.Push(20);
  EXPECT_EQ(s.Pop(), 20);
  EXPECT_EQ(s.Pop(), 10);
}

TEST(StackTest, IsEmptyOnInitialization) {
  Stack s(5);
  EXPECT_TRUE(s.IsEmpty());
}

TEST(StackTest, IsEmptyAfterPop) {
  Stack s(5);
  s.Push(1);
  s.Pop();
  EXPECT_TRUE(s.IsEmpty());
}

TEST(StackTest, PopOnEmptyStack) {
  Stack s(5);
  ASSERT_DEATH(s.Pop(), "Out-of-bound");
}  // 빈 스택에서 Pop을 호출하면 예외 발생

TEST(StackTest, PushBeyondCapacity) {
  Stack s(2);
  s.Push(1);
  s.Push(2);
  s.Push(3);  // 스택 확장을 허용하면 예외가 발생하지 않아야 함
  EXPECT_EQ(s.Pop(), 3);
}

// List 테스트
TEST(ListTest, PushBackAndAt) {
  List list;
  list.PushBack(10);
  list.PushBack(20);
  EXPECT_EQ(list.At(0), 10);
  EXPECT_EQ(list.At(1), 20);
}

TEST(ListTest, PushFrontAndAt) {
  List list;
  list.PushBack(10);
  list.PushFront(5);
  EXPECT_EQ(list.At(0), 5);
  EXPECT_EQ(list.At(1), 10);
}

TEST(ListTest, PopBackReturn) {
  List list;
  list.PushBack(10);
  list.PushBack(20);
  EXPECT_EQ(list.PopBackReturn(), 20);
}

TEST(ListTest, PopFrontAndSize) {
  List list;
  list.PushBack(10);
  list.PushBack(20);
  list.PopFront();
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.At(0), 20);
}

TEST(ListTest, OutOfBoundsAt) {
  List list;
  list.PushBack(10);
  ASSERT_DEATH(list.At(1), "Out-of-bound");
}  // 범위를 벗어난 접근이므로 에러 발생

// Queue 테스트
TEST(QueueTest, AddAndPollOrder) {
  Queue q;
  q.Add(5);
  q.Add(10);
  EXPECT_EQ(q.Poll(), 5);
  EXPECT_EQ(q.Poll(), 10);
}

TEST(QueueTest, IsEmptyOnInitialization) {
  Queue q;
  EXPECT_TRUE(q.IsEmpty());
}

TEST(QueueTest, IsEmptyAfterPollingAll) {
  Queue q;
  q.Add(1);
  q.Poll();
  EXPECT_TRUE(q.IsEmpty());
}

TEST(QueueTest, PollOnEmptyQueue) {
  Queue q;
  ASSERT_DEATH(q.Poll(), "Out-of-bound");
}  // 빈 큐에서 Poll을 호출하면 예외 발생

TEST(QueueTest, SizeAfterAdd) {
  Queue q;
  q.Add(5);
  q.Add(10);
  EXPECT_EQ(q.size(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
