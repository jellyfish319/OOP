#ifndef PREORDER_TRAVERSAL_H
#define PREORDER_TRAVERSAL_H

#include <string>
#include "visitor.h"
#include "int_node.h"
#include "string_node.h"

class PreorderTraversal : public Visitor {
 public:
  void EnterIntNode(IntNode* node);
  void ExitIntNode(IntNode* node);
  void EnterStringNode(StringNode* node);
  void ExitStringNode(StringNode* node);
  std::string Result();
 private:
  std::string result_;
};

#endif  // PREORDER_TRAVERSAL_H

