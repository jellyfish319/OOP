#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"
#include <typeinfo>

TreeUtil* TreeUtil::instance_ = nullptr;

TreeUtil* TreeUtil::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new TreeUtil();
  }
  return instance_;
}

TreeUtil::TreeUtil() {}

const std::string TreeUtil::PreOrder(const Node* node) const {
  std::string result;
  if (node != nullptr) {
    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
      result += std::to_string(intNode->value()) + ",";
    } else if (const StringNode* strNode =
    dynamic_cast<const StringNode*>(node)) {
      result += strNode->value() + ",";
    }
    result += PreOrder(node->left());
    result += PreOrder(node->right());
  }
  return result;
}

const std::string TreeUtil::PreOrderTraversal(const Node* node) const {
  std::string result;
  result = PreOrder(node);
  return result.substr(0, result.size() - 1);
}

const std::string TreeUtil::InOrder(const Node* node) const {
  std::string result;
  if (node != nullptr) {
    result += InOrder(node->left());
    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
      result += std::to_string(intNode->value()) + ",";
    } else if (const StringNode* strNode =
    dynamic_cast<const StringNode*>(node)) {
      result += strNode->value() + ",";
    }
    result += InOrder(node->right());
  }
  return result;
}

const std::string TreeUtil::InOrderTraversal(const Node* node) const {
  std::string result;
  result = InOrder(node);
  return result.substr(0, result.size() - 1);
}

const std::string TreeUtil::PostOrder(const Node* node) const {
  std::string result;
  if (node != nullptr) {
    result += PostOrder(node->left());
    result += PostOrder(node->right());
    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
      result += std::to_string(intNode->value()) + ",";
    } else if (const StringNode* strNode =
    dynamic_cast<const StringNode*>(node)) {
      result += strNode->value() + ",";
    }
  }
  return result;
}

const std::string TreeUtil::PostOrderTraversal(const Node* node) const {
  std::string result;
  result = PostOrder(node);
  return result.substr(0, result.size() - 1);
}
