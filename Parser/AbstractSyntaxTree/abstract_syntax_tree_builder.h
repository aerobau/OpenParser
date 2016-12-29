//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_TREE_BUILDER_H
#define PARSER_TREE_BUILDER_H


#include <string>
#include <stack>
#include "abstract_syntax_tree_node.h"
#include "abstract_syntax_tree.h"

class AbstractSyntaxTreeBuilder {
public:
    void BuildTree(std::string, int);
    AbstractSyntaxTree FinishedTree();
private:
    std::stack<AbstractSyntaxTreeNode> tree_node_stack_;
};

#endif //PARSER_TREE_BUILDER_H
