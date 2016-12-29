//
// Created by Alexander Robau on 12/15/16.
//

#include <sstream>
#include "abstract_syntax_tree_builder.h"

void AbstractSyntaxTreeBuilder::BuildTree(std::string name, int number_of_children) {
    AbstractSyntaxTreeNode node = AbstractSyntaxTreeNode(name);
    while(number_of_children-- != 0) {
        node.AddChild(tree_node_stack_.top());
        tree_node_stack_.pop();
    }
    tree_node_stack_.push(node);
}

AbstractSyntaxTree AbstractSyntaxTreeBuilder::FinishedTree() {
    if (tree_node_stack_.size() != 1) {
        std::stringstream concat;
        concat << "Tree does not seem to be finished, built tree may be malformed. Current stack size: "
               << tree_node_stack_.size();
        throw std::exception();
    }
    else {
        AbstractSyntaxTree tree = AbstractSyntaxTree(tree_node_stack_.top());
    }
}



