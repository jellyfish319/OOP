#ifndef INT_NODE_H
#define INT_NODE_H

#include <string>
#include "visitor.h"
#include "node.h"

class IntNode : public Node {
 public:
  explicit IntNode(int value, Node* left, Node* right);
  void Visit(Visitor* visitor);
  std::string value();  // value_를 string으로 return
 private:
  int value_;
};

#endif  // INT_NODE_H

