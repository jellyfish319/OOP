#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class IntNode;
class StringNode;

class Visitor {
 public:
  virtual void EnterIntNode(IntNode* node) = 0;
  virtual void ExitIntNode(IntNode* node) = 0;
  virtual void EnterStringNode(StringNode* node) = 0;
  virtual void ExitStringNode(StringNode* node) = 0;
  virtual std::string Result() = 0;
};

#endif  // VISITOR_H
