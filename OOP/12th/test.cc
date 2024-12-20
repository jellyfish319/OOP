#include <gtest/gtest.h>
#include "safe_int.h"
#include "list.h"
#include "vector.h"
#include "divide_by_zero_exception.h"
#include "empty_container_exception.h"

// SafeInt 테스트
TEST(SafeIntTest, AdditionWorks) {
    SafeInt a(10);
    SafeInt b(20);
    EXPECT_EQ((a + b).value(), 30);
}

TEST(SafeIntTest, AdditionOverflowThrows) {
    SafeInt a(std::numeric_limits<int>::max());
    SafeInt b(1);
    EXPECT_THROW(a + b, std::overflow_error);
}

TEST(SafeIntTest, DivisionByZeroThrows) {
    SafeInt a(10);
    SafeInt b(0);
    EXPECT_THROW(a / b, DivideByZeroException);
}

TEST(SafeIntTest, AdditionOverflowMessage) {
    SafeInt a(std::numeric_limits<int>::max());
    SafeInt b(1);

    try {
        a + b;
    } catch (const std::overflow_error& e) {
        EXPECT_STREQ(e.what(), "Integer overflow occurs in 2147483647 + 1");
    }
}

TEST(SafeIntTest, SubtractionOverflowMessage) {
    SafeInt a(std::numeric_limits<int>::min());
    SafeInt b(1);

    try {
        a - b;
    } catch (const std::overflow_error& e) {
        EXPECT_STREQ(e.what(), "Integer overflow occurs in -2147483648 - 1");
    }
}

TEST(SafeIntTest, MultiplicationOverflowMessage) {
    SafeInt a(std::numeric_limits<int>::max());
    SafeInt b(2);

    try {
        a * b;
    } catch (const std::overflow_error& e) {
        EXPECT_STREQ(e.what(), "Integer overflow occurs in 2147483647 * 2");
    }
}

TEST(SafeIntTest, DivisionByZeroMessage) {
    SafeInt a(10);
    SafeInt b(0);

    try {
        a / b;
    } catch (const DivideByZeroException& e) {
        EXPECT_STREQ(e.what(), "Divide-by-zero exception occurs in 10/0");
    }
}

// List 테스트
TEST(ListTest, PushBackAndAtWorks) {
    List<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    EXPECT_EQ(list.At(0), 1);
    EXPECT_EQ(list.At(1), 2);
    EXPECT_EQ(list.At(2), 3);
}

TEST(ListTest, PopBackOnEmptyThrows) {
    List<int> list;
    EXPECT_THROW(list.PopBack(), EmptyContainerException);
}

TEST(ListTest, AtOutOfRangeThrows) {
    List<int> list;
    list.PushBack(10);
    EXPECT_THROW(list.At(1), std::out_of_range);
}

TEST(ListTest, PopBackOnEmptyMessage) {
    List<int> list;

    try {
        list.PopBack();
    } catch (const EmptyContainerException& e) {
        EXPECT_STREQ(e.what(), "This list is empty");
    }
}

TEST(ListTest, AtOutOfRangeMessage) {
    List<int> list;
    list.PushBack(10);

    try {
        list.At(2);
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "The index is 2, but the size is 1");
    }
}

// Vector 테스트
TEST(VectorTest, PushBackAndAccessWorks) {
    Vector<int> vector(2);
    vector.PushBack(5);
    vector.PushBack(10);
    EXPECT_EQ(vector[0], 5);
    EXPECT_EQ(vector[1], 10);
}

TEST(VectorTest, PopBackOnEmptyThrows) {
    Vector<int> vector(2);
    EXPECT_THROW(vector.PopBack(), EmptyContainerException);
}

TEST(VectorTest, AccessOutOfRangeThrows) {
    Vector<int> vector(2);
    vector.PushBack(5);
    EXPECT_THROW(vector[1], std::out_of_range);
}

TEST(VectorTest, PopBackOnEmptyMessage) {
    Vector<int> vector(5);

    try {
        vector.PopBack();
    } catch (const EmptyContainerException& e) {
        EXPECT_STREQ(e.what(), "This vector is empty");
    }
}

TEST(VectorTest, AccessOutOfRangeMessage) {
    Vector<int> vector(5);
    vector.PushBack(10);

    try {
        vector[2];
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "The index is 2, but the size is 1");
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
