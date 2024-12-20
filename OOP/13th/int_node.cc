#include "int_node.h"

IntNode::IntNode(int value, Node* left, Node* right) :
value_(value), Node(left, right) {}

void IntNode::Visit(Visitor* visitor) {
  visitor->EnterIntNode(this);
  if (left_) left_->Visit(visitor);
  if (right_) right_->Visit(visitor);
  visitor->ExitIntNode(this);
}


std::string IntNode::value() {
  std::string v = "(Int ";
  v += std::to_string(value_);
  v += ") :: ";
  return v;
}
