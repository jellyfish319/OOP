#include "postorder_traversal.h"

void PostorderTraversal::EnterIntNode(IntNode* node) {
  if (node == nullptr) {
    return;
  }
}

void PostorderTraversal::ExitIntNode(IntNode* node) {
  if (node == nullptr) {
    return;
  }
  result_ += node->value();
}

void PostorderTraversal::EnterStringNode(StringNode* node) {
  if (node == nullptr) {
    return;
  }
}

void PostorderTraversal::ExitStringNode(StringNode* node) {
  if (node == nullptr) {
    return;
  }
  result_ += node->value();
}

std::string PostorderTraversal::Result() {
  int len = result_.length();
  return result_.substr(0, len-4);
}
