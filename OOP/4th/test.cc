#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 public:
    IntSetTest() : test_(6) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    IntSet test_;
};

TEST_F(IntSetTest, IntSetTest0) {
  test_.Add(1);
  test_.Add(2);
  test_.Add(3);
  EXPECT_EQ(test_.size(), 3);
  EXPECT_EQ(test_.capacity(), 6);
  EXPECT_EQ(test_.elements()[0], 1);
}  // Basic function run

TEST_F(IntSetTest, IntSetTest1) {
  test_.Add(1);
  test_.Add(2);
  test_.Add(2);
  EXPECT_EQ(test_.size(), 2);
}  // Add function run

TEST_F(IntSetTest, IntSetTest2) {
  test_.Add(1);
  test_.Add(2);
  EXPECT_EQ(test_.size(), 2);
}

TEST_F(IntSetTest, IntSetTest3) {
  test_.Add(1);
  test_.Add(2);
  test_.Add(3);
  test_.Add(4);
  test_.Add(5);
  test_.Add(6);
  ASSERT_DEATH(test_.Add(7), "Exceeded capacity");
}  // Esceeded capacity check of Add function

TEST_F(IntSetTest, IntSetTest4) {
  test_.Add(1);
  test_.Add(2);
  EXPECT_EQ(test_.elements()[0], 1);
}  // Add function at set

TEST_F(IntSetTest, IntSetTest5) {
  test_.Add(1);
  test_.Add(2);
  IntSet copy_set_ = test_;
  for (int i = 0; i < copy_set_.size(); i++) {
    EXPECT_EQ(test_.elements()[i], copy_set_.elements()[i]);
  }
}  // Check copyconstructor

TEST_F(IntSetTest, IntSetTest6) {
  test_.Add(1);
  test_.Add(2);
  IntSet copy_set_ = test_;
  copy_set_.Add(3);
  ASSERT_EQ(test_.size(), 2);
  ASSERT_EQ(copy_set_.size(), 3);
}  // Check Deep Copy

TEST_F(IntSetTest, IntSetTest7) {
  test_.Add(2);
  test_.Add(1);
  test_.Add(3);
  IntSet set_(5);
  set_.Add(5);
  set_.Add(3);
  set_.Add(2);

  test_.Add(set_);
  EXPECT_EQ(test_.size(), 4);
  EXPECT_EQ(test_.elements()[0], 2);
  EXPECT_EQ(test_.elements()[1], 1);
  EXPECT_EQ(test_.elements()[2], 3);
  EXPECT_EQ(test_.elements()[3], 5);
}  // Check duplicate elements

TEST_F(IntSetTest, IntSetTest8) {
  test_.Add(1);
  test_.Add(2);
  IntSet set_(5);
  set_.Add(3);
  set_.Add(4);
  set_.Add(5);
  set_.Add(6);
  set_.Add(7);
  ASSERT_DEATH(test_.Add(set_), "Exceeded capacity");
}  // Exceeded capacity check of Add function at set

TEST_F(IntSetTest, IntSetTest9) {
  test_.Add(1);
  test_.Add(2);
  test_.Map([](int x) { return x * 2; });
  EXPECT_EQ(test_.elements()[0], 2);
  EXPECT_EQ(test_.elements()[1], 4);
}  // Map function

TEST_F(IntSetTest, IntSetTest10) {
  test_.Add(1);
  test_.Add(2);
  bool result = test_.ForAll([](int x) { return x > 0; });
  EXPECT_TRUE(result);
}  // ForAll function - true case

TEST_F(IntSetTest, IntSetTest11) {
  test_.Add(1);
  test_.Add(2);
  test_.Add(3);
  bool result = test_.ForAll([](int x) { return x > 2; });
  EXPECT_TRUE(!result);
}  // ForAll function - false case
