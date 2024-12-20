#include "preorder_traversal.h"
#include "int_node.h"
#include "string_node.h"

void PreorderTraversal::EnterIntNode(IntNode* node) {
  if (node == nullptr) {
    return;
  }
  result_ += node->value();
}

void PreorderTraversal::ExitIntNode(IntNode* node) {
  if (node == nullptr) {
    return;
  }
}

void PreorderTraversal::EnterStringNode(StringNode* node) {
  if (node == nullptr) {
    return;
  }
  result_ += node->value();
}

void PreorderTraversal::ExitStringNode(StringNode* node) {
  if (node == nullptr) {
    return;
  }
}

std::string PreorderTraversal::Result() {
  int len = result_.length();
  return result_.substr(0, len-4);
}

