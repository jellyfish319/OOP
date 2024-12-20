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

TEST_F(IntSetTest, IntSetTest1) {
  test_.Add(1);
  test_.Add(2);
  test_.Add(3);
  EXPECT_EQ(test_.size(), 3);
  EXPECT_EQ(test_.capacity(), 6);
  EXPECT_EQ(test_.elements()[0], 1);
}  // Basic function run


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
  test_.Add(7);
  EXPECT_EQ(test_.capacity(), 10);
}  // extended capacity check of Add function

TEST_F(IntSetTest, IntSetTest4) {
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
}  // Add function at set

TEST_F(IntSetTest, IntSetTest5) {
  test_.Add(1);
  test_.Add(2);
  test_.Add(10);
  test_.Add(11);
  test_.Add(12);
  test_.Add(13);
  IntSet set_(5);
  set_.Add(3);
  set_.Add(4);
  set_.Add(5);
  set_.Add(6);
  set_.Add(7);
  test_.Add(set_);
  EXPECT_EQ(test_.capacity(), 14);
}

TEST_F(IntSetTest, IntSetTest6) {
  test_.Add(1);
  test_.Add(2);
  IntSet set_(5);
  set_.Add(3);
  set_.Add(4);
  set_.Add(2);
  test_.Add(set_);
  EXPECT_EQ(test_.capacity(), 6);
  EXPECT_EQ(test_.elements()[1], 2);
  EXPECT_EQ(test_.size(), 4);
}  // Check Duplicate elements

TEST_F(IntSetTest, IntSetTest7) {
  test_.Add(1);
  test_.Add(12);
  test_.Add(88);
  EXPECT_EQ(test_[2], 88);
  EXPECT_EQ(test_[0], 1);
}  // Operator

TEST_F(IntSetTest, IntSetTest8) {
  test_.Add(1);
  test_.Add(12);
  test_.Add(88);
  ASSERT_DEATH(test_[5], "Out-of-bound");
  ASSERT_DEATH(test_[-1], "Out-of-bound");
}  // Check Exceeded case about operator

TEST_F(IntSetTest, IntSetTest9) {
  test_.Add(1);
  test_.Add(12);
  test_.Add(88);
  ASSERT_DEATH(test_[-1], "Out-of-bound");
}  // Map function
