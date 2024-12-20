#include "string_node.h"

StringNode::StringNode(std::string value, Node* left, Node* right)
: value_(value), Node(left, right)  {}

void StringNode::Visit(Visitor* visitor) {
  visitor->EnterStringNode(this);
  if (left_) left_->Visit(visitor);
  if (right_) right_->Visit(visitor);
  visitor->ExitStringNode(this);
}

std::string StringNode::value() {
  return std::string("(String " +  value_ + ") :: ");
}
