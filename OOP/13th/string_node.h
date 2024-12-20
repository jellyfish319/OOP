#ifndef STRING_NODE_H
#define STRING_NODE_H

#include <string>
#include "node.h"
#include "visitor.h"

class StringNode : public Node {
 public:
  explicit StringNode(std::string value, Node* left, Node* right);
  void Visit(Visitor* visitor);
  std::string value();
 private:
  std::string value_;
};

#endif  // STRING_NODE_H
