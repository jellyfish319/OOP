#include "gtest/gtest.h"
#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"

class TreeUtilTest : public ::testing::Test {
 public:
  TreeUtilTest() {
    right_int_node = new IntNode(3, nullptr, nullptr);
    left_int_node = new IntNode(2, nullptr, nullptr);
    root_int_node = new IntNode(1, left_int_node, right_int_node);

    right_str_node = new StringNode("right", nullptr, nullptr);
    left_str_node = new StringNode("left", nullptr, nullptr);
    root_str_node = new StringNode("root", left_str_node, right_str_node);

    three = new IntNode(3, nullptr, nullptr);
    five = new IntNode(5, nullptr, nullptr);
    mango = new StringNode("mango", nullptr, nullptr);
    apple = new StringNode("apple", nullptr, three);
    banana = new StringNode("banana", mango, nullptr);
    peach = new StringNode("peach", five, banana);
    grape = new StringNode("grape", peach, apple);

    tree_util = TreeUtil::GetInstance();
  }

  ~TreeUtilTest() override {
    delete right_int_node;
    delete left_int_node;
    delete root_int_node;

    delete right_str_node;
    delete left_str_node;
    delete root_str_node;

    delete grape;
    delete mango;
    delete peach;
    delete apple;
    delete banana;
    delete five;
    delete three;
  }

 protected:
  Node* root_int_node;
  Node* left_int_node;
  Node* right_int_node;

  Node* root_str_node;
  Node* left_str_node;
  Node* right_str_node;

  Node* grape;
  Node* mango;
  Node* peach;
  Node* apple;
  Node* banana;
  Node* five;
  Node* three;

  TreeUtil* tree_util;
};

// PreOrderTraversal 테스트
TEST_F(TreeUtilTest, PreOrderTraversalTest) {
  EXPECT_EQ(tree_util->PreOrderTraversal(root_int_node), "1,2,3");
  EXPECT_EQ(tree_util->PreOrderTraversal(root_str_node), "root,left,right");
  EXPECT_EQ(tree_util->PreOrderTraversal(grape),
  "grape,peach,5,banana,mango,apple,3");
}

// InOrderTraversal 테스트
TEST_F(TreeUtilTest, InOrderTraversalTest) {
  EXPECT_EQ(tree_util->InOrderTraversal(root_int_node), "2,1,3");
  EXPECT_EQ(tree_util->InOrderTraversal(root_str_node), "left,root,right");
  EXPECT_EQ(tree_util->InOrderTraversal(grape),
  "5,peach,mango,banana,grape,apple,3");
}

// PostOrderTraversal 테스트
TEST_F(TreeUtilTest, PostOrderTraversalTest) {
  EXPECT_EQ(tree_util->PostOrderTraversal(root_int_node), "2,3,1");
  EXPECT_EQ(tree_util->PostOrderTraversal(root_str_node), "left,right,root");
  EXPECT_EQ(tree_util->PostOrderTraversal(grape),
  "5,mango,banana,peach,3,apple,grape");
}
