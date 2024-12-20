#include <gtest/gtest.h>
#include "preorder_traversal.h"
#include "postorder_traversal.h"
#include "int_node.h"
#include "string_node.h"

// IntNode 테스트
TEST(IntNodeTest, PreorderTraversalTest) {
  IntNode one(1, nullptr, nullptr);
  IntNode zero(0, nullptr, nullptr);
  IntNode n_one(-1, nullptr, nullptr);
  IntNode four(-42, &zero, &n_one);
  IntNode three(3, &one, &four);

  PreorderTraversal visitor;
  three.Visit(&visitor);
  EXPECT_EQ(visitor.Result(),
  "(Int 3) :: (Int 1) :: (Int -42) :: (Int 0) :: (Int -1)");
}

TEST(IntNodeTest, PostorderTraversalTest) {
  IntNode one(1, nullptr, nullptr);
  IntNode zero(0, nullptr, nullptr);
  IntNode n_one(-1, nullptr, nullptr);
  IntNode four(-42, &zero, &n_one);
  IntNode three(3, &one, &four);

  PostorderTraversal visitor;
  three.Visit(&visitor);
  EXPECT_EQ(visitor.Result(),
  "(Int 1) :: (Int 0) :: (Int -1) :: (Int -42) :: (Int 3)");
}

// StringNode 테스트

TEST(StringNodeTest, PreorderTraversal) {
  StringNode mango("mango", nullptr, nullptr);
  StringNode grape("grape", nullptr, nullptr);
  StringNode apple("apple", nullptr, nullptr);
  StringNode pear("pear", nullptr, nullptr);
  StringNode peach("peach", &grape, nullptr);
  StringNode avocado("avocado", &apple, &pear);
  StringNode strawberry("strawberry", &mango, &peach);
  StringNode banana("banana", &avocado, nullptr);
  StringNode mellon("mellon", &strawberry, &banana);

  PreorderTraversal visitor;
  mellon.Visit(&visitor);
  std::string result = "(String mellon) :: (String strawberry) :: (String man";
  result +=  "go) :: (String peach) :: (String grape) :: (String banana) :: ";
  result += "(String avocado) :: (String apple) :: (String pear)";
  EXPECT_EQ(visitor.Result(), result);
}

TEST(StringNodeTest, PostorderTraversal) {
  StringNode mango("mango", nullptr, nullptr);
  StringNode grape("grape", nullptr, nullptr);
  StringNode apple("apple", nullptr, nullptr);
  StringNode pear("pear", nullptr, nullptr);
  StringNode peach("peach", &grape, nullptr);
  StringNode avocado("avocado", &apple, &pear);
  StringNode strawberry("strawberry", &mango, &peach);
  StringNode banana("banana", &avocado, nullptr);
  StringNode mellon("mellon", &strawberry, &banana);

  PostorderTraversal visitor;
  mellon.Visit(&visitor);
  std::string result = "(String mango) :: (String grape) :: (String ";
  result +=  "peach) :: (String strawberry) :: (String apple) :: (String pear)";
  result +=  " :: (String avocado) :: (String banana) :: (String mellon)";
  EXPECT_EQ(visitor.Result(), result);
}

// MixedNode 테스트

TEST(MixedNodeTest, PreorderTraversalTest) {
  StringNode hi("hi", nullptr, nullptr);
  IntNode zero(0, nullptr, nullptr);
  StringNode bye("bye", nullptr, nullptr);
  IntNode four(-42, &zero, &bye);
  IntNode three(3, &hi, &four);

  PreorderTraversal visitor;
  three.Visit(&visitor);
  EXPECT_EQ(visitor.Result(),
  "(Int 3) :: (String hi) :: (Int -42) :: (Int 0) :: (String bye)");
}

TEST(MixedNodeTest, PostorderTraversalTest) {
  StringNode hi("hi", nullptr, nullptr);
  IntNode zero(0, nullptr, nullptr);
  StringNode bye("bye", nullptr, nullptr);
  IntNode four(-42, &zero, &bye);
  IntNode three(3, &hi, &four);

  PostorderTraversal visitor;
  three.Visit(&visitor);
  EXPECT_EQ(visitor.Result(),
  "(String hi) :: (Int 0) :: (String bye) :: (Int -42) :: (Int 3)");
}
