#include <gtest/gtest.h>
#include "vector.h"
#include "stack.h"
#include "list.h"
#include "queue.h"
#include <string>

// Vector 테스트
TEST(VectorTest, PushBackAndAccess) {
  Vector<int> v(5);
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, SizeAfterPushBack) {
  Vector<int> v(5);
  v.PushBack(1);
  EXPECT_EQ(v.size(), 1);
  v.PushBack(2);
  EXPECT_EQ(v.size(), 2);
  v.PushBack(3);
  v.PushBack(4);
  v.PushBack(5);
  v.PushBack(6);
  EXPECT_EQ(v.size(), 6);
  EXPECT_EQ(v.capacity(), 9);
}

TEST(VectorTest, Capacity) {
  Vector<int> v(5);
  EXPECT_EQ(v.capacity(), 5);
  v.PushBack(1);
  EXPECT_EQ(v.capacity(), 5);
}

TEST(VectorTest, PopBackReducesSize) {
  Vector<int> v(5);
  v.PushBack(1);
  v.PushBack(2);
  v.PopBack();
  EXPECT_EQ(v.size(), 1);
}

TEST(VectorTest, OutOfBoundsAccess) {
  Vector<int> v(5);
  v.PushBack(1);
  ASSERT_DEATH(v[5], "Out-of-bound");
}  // 범위를 벗어난 접근이므로 에러가 발생해야 함

// Stack 테스트
TEST(StackTest, PushAndPopOrder) {
  Stack<int> s(5);
  s.Push(10);
  s.Push(20);
  EXPECT_EQ(s.Pop(), 20);
  EXPECT_EQ(s.Pop(), 10);
}

TEST(StackTest, IsEmptyOnInitialization) {
  Stack<int> s(5);
  EXPECT_TRUE(s.IsEmpty());
}

TEST(StackTest, IsEmptyAfterPop) {
  Stack<int> s(5);
  s.Push(1);
  s.Pop();
  EXPECT_TRUE(s.IsEmpty());
}

TEST(StackTest, PopOnEmptyStack) {
  Stack<int> s(5);
  ASSERT_DEATH(s.Pop(), "Out-of-bound");
}  // 빈 스택에서 Pop을 호출하면 예외 발생

TEST(StackTest, PushBeyondCapacity) {
  Stack<int> s(2);
  s.Push(1);
  s.Push(2);
  s.Push(3);  // 스택 확장을 허용하면 예외가 발생하지 않아야 함
  EXPECT_EQ(s.Pop(), 3);
}

// List 테스트
TEST(ListTest, PushBackAndAt) {
  List<int> list;
  list.PushBack(10);
  list.PushBack(20);
  EXPECT_EQ(list.At(0), 10);
  EXPECT_EQ(list.At(1), 20);
}

TEST(ListTest, PushFrontAndAt) {
  List<int> list;
  list.PushBack(10);
  list.PushFront(5);
  EXPECT_EQ(list.At(0), 5);
  EXPECT_EQ(list.At(1), 10);
}

TEST(ListTest, PopBackReturn) {
  List<int> list;
  list.PushBack(10);
  list.PushBack(20);
  EXPECT_EQ(list.PopBackReturn(), 20);
}

TEST(ListTest, PopFrontAndSize) {
  List<int> list;
  list.PushBack(10);
  list.PushBack(20);
  list.PopFront();
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.At(0), 20);
}

TEST(ListTest, OutOfBoundsAt) {
  List<int> list;
  list.PushBack(10);
  ASSERT_DEATH(list.At(1), "Out-of-bound");
}  // 범위를 벗어난 접근이므로 에러 발생

// Queue 테스트
TEST(QueueTest, AddAndPollOrder) {
  Queue<int> q;
  q.Add(5);
  q.Add(10);
  EXPECT_EQ(q.Poll(), 5);
  EXPECT_EQ(q.Poll(), 10);
}

TEST(QueueTest, IsEmptyOnInitialization) {
  Queue<int> q;
  EXPECT_TRUE(q.IsEmpty());
}

TEST(QueueTest, IsEmptyAfterPollingAll) {
  Queue<int> q;
  q.Add(1);
  q.Poll();
  EXPECT_TRUE(q.IsEmpty());
}

TEST(QueueTest, PollOnEmptyQueue) {
  Queue<int> q;
  ASSERT_DEATH(q.Poll(), "Out-of-bound");
}  // 빈 큐에서 Poll을 호출하면 예외 발생

TEST(QueueTest, SizeAfterAdd) {
  Queue<int> q;
  q.Add(5);
  q.Add(10);
  EXPECT_EQ(q.size(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// List 테스트: Size 변화 확인
TEST(ListTest, SizeIncreasesCorrectly) {
  List<int> list;
  EXPECT_EQ(list.size(), 0);
  list.PushBack(10);
  EXPECT_EQ(list.size(), 1);
  list.PushBack(20);
  EXPECT_EQ(list.size(), 2);
  list.PushBack(30);
  EXPECT_EQ(list.size(), 3);
}

// List 테스트: 다양한 데이터 타입 확인
TEST(ListTest, TemplateTypeSupport) {
  List<int> intList;
  intList.PushBack(42);
  EXPECT_EQ(intList.At(0), 42);

  List<double> doubleList;
  doubleList.PushBack(3.14);
  EXPECT_DOUBLE_EQ(doubleList.At(0), 3.14);

  List<std::string> stringList;
  stringList.PushBack("Hello");
  EXPECT_EQ(stringList.At(0), "Hello");

  struct TestStruct {
    int id;
    std::string name;
  };
  List<TestStruct> structList;
  structList.PushBack({1, "Test"});
  EXPECT_EQ(structList.At(0).id, 1);
  EXPECT_EQ(structList.At(0).name, "Test");
}

// Stack 테스트: Size 변화 확인
TEST(StackTest, SizeIncreasesCorrectly) {
  Stack<int> stack(3);
  EXPECT_EQ(stack.size(), 0);
  stack.Push(10);
  EXPECT_EQ(stack.size(), 1);
  stack.Push(20);
  EXPECT_EQ(stack.size(), 2);
  stack.Push(30);
  EXPECT_EQ(stack.size(), 3);
}

// Stack 테스트: 다양한 데이터 타입 확인
TEST(StackTest, TemplateTypeSupport) {
  Stack<int> intStack(2);
  intStack.Push(42);
  EXPECT_EQ(intStack.Pop(), 42);

  Stack<double> doubleStack(2);
  doubleStack.Push(3.14);
  EXPECT_DOUBLE_EQ(doubleStack.Pop(), 3.14);

  Stack<std::string> stringStack(2);
  stringStack.Push("Hello");
  EXPECT_EQ(stringStack.Pop(), "Hello");

  struct TestStruct {
    int id;
    std::string name;
  };
  Stack<TestStruct> structStack(2);
  structStack.Push({1, "Test"});
  auto elem = structStack.Pop();
  EXPECT_EQ(elem.id, 1);
  EXPECT_EQ(elem.name, "Test");
}

// Queue 테스트: Size 변화 확인
TEST(QueueTest, SizeIncreasesCorrectly) {
  Queue<int> queue;
  EXPECT_EQ(queue.size(), 0);
  queue.Add(10);
  EXPECT_EQ(queue.size(), 1);
  queue.Add(20);
  EXPECT_EQ(queue.size(), 2);
  queue.Add(30);
  EXPECT_EQ(queue.size(), 3);
}

// Queue 테스트: 다양한 데이터 타입 확인
TEST(QueueTest, TemplateTypeSupport) {
  Queue<int> intQueue;
  intQueue.Add(42);
  EXPECT_EQ(intQueue.Poll(), 42);

  Queue<double> doubleQueue;
  doubleQueue.Add(3.14);
  EXPECT_DOUBLE_EQ(doubleQueue.Poll(), 3.14);

  Queue<std::string> stringQueue;
  stringQueue.Add("Hello");
  EXPECT_EQ(stringQueue.Poll(), "Hello");

  struct TestStruct {
    int id;
    std::string name;
  };
  Queue<TestStruct> structQueue;
  structQueue.Add({1, "Test"});
  auto elem = structQueue.Poll();
  EXPECT_EQ(elem.id, 1);
  EXPECT_EQ(elem.name, "Test");
}

// Vector 테스트: Size 변화 확인
TEST(VectorTest, SizeIncreasesCorrectly) {
  Vector<int> v(3);
  EXPECT_EQ(v.size(), 0);  // 초기 사이즈는 0이어야 함
  v.PushBack(10);
  EXPECT_EQ(v.size(), 1);
  v.PushBack(20);
  EXPECT_EQ(v.size(), 2);
  v.PushBack(30);
  EXPECT_EQ(v.size(), 3);

  // capacity 증가를 유도
  v.PushBack(40);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v.capacity(), 7);  // 초기 3에서 +4 증가
}

// Vector 테스트: 다양한 데이터 타입 확인
TEST(VectorTest, TemplateTypeSupport) {
  // int 타입
  Vector<int> intVec(2);
  intVec.PushBack(42);
  EXPECT_EQ(intVec[0], 42);

  // double 타입
  Vector<double> doubleVec(2);
  doubleVec.PushBack(3.14);
  EXPECT_DOUBLE_EQ(doubleVec[0], 3.14);

  // std::string 타입
  Vector<std::string> stringVec(2);
  stringVec.PushBack("Hello");
  EXPECT_EQ(stringVec[0], "Hello");

  // 사용자 정의 타입
  struct TestStruct {
    int id;
    std::string name;
  };
  Vector<TestStruct> structVec(2);
  structVec.PushBack({1, "Test"});
  EXPECT_EQ(structVec[0].id, 1);
  EXPECT_EQ(structVec[0].name, "Test");
}

// Vector 테스트: Capacity 증가 검증
TEST(VectorTest, CapacityExpandsCorrectly) {
  Vector<int> v(2);
  EXPECT_EQ(v.capacity(), 2);

  // Capacity 증가 유도
  v.PushBack(1);
  v.PushBack(2);
  EXPECT_EQ(v.capacity(), 2);  // 아직 증가하지 않음
  v.PushBack(3);
  EXPECT_EQ(v.capacity(), 6);  // 2에서 +4로 증가
  v.PushBack(4);
  v.PushBack(5);
  v.PushBack(6);
  v.PushBack(7);
  EXPECT_EQ(v.capacity(), 10);  // 추가 증가
}

TEST(VectorTest, DeepCopyConstructor) {
  Vector<int> v1(3);
  v1.PushBack(10);
  v1.PushBack(20);

  Vector<int> v2 = v1;  // 복사 생성자 호출
  v2.PushBack(30);

  EXPECT_EQ(v1.size(), 2);  // 원본에는 영향을 미치지 않음
  EXPECT_EQ(v2.size(), 3);
}
