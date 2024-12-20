#ifndef _TREE_UTIL_H_
#define _TREE_UTIL_H_

#include <iostream>
#include <string>
#include "node.h"

class TreeUtil {
 public:
    static TreeUtil* GetInstance();
    const std::string PreOrderTraversal(const Node* node) const;
    const std::string InOrderTraversal(const Node* node) const;
    const std::string PostOrderTraversal(const Node* node) const;
    const std::string PreOrder(const Node* node) const;
    const std::string InOrder(const Node* node) const;
    const std::string PostOrder(const Node* node) const;
 private:
    TreeUtil();
    static TreeUtil* instance_;
};


#endif  // _TREE_UTIL_H_
