//
// Created by Alexander Robau on 12/24/16.
//

#include <sstream>
#include "abstract_syntax_tree_node.h"

// MARK: PUBLIC CONSTRUCTORS

AbstractSyntaxTreeNode::AbstractSyntaxTreeNode() : name_(""), parent_(nullptr) { }

AbstractSyntaxTreeNode::AbstractSyntaxTreeNode(std::string name) : name_(name), parent_(nullptr) { }

// MARK: PUBLIC FUNCTIONS

AbstractSyntaxTreeNode* AbstractSyntaxTreeNode::parent() {
    return parent_;
}

std::size_t AbstractSyntaxTreeNode::ChildrenCount() {
    return children_.size();
}

AbstractSyntaxTreeNode* AbstractSyntaxTreeNode::GetChild(int child_number) {
    return children_[child_number].get();
}

void AbstractSyntaxTreeNode::AddChild(AbstractSyntaxTreeNode tree_node) {
    AbstractSyntaxTreeNode* copy_ptr = new AbstractSyntaxTreeNode(tree_node);
    copy_ptr->parent_ = this;
    children_.push_back(std::unique_ptr<AbstractSyntaxTreeNode>(copy_ptr));
}

void AbstractSyntaxTreeNode::AddDecoration(std::string name, AbstractSyntaxTreeNode* decoration_node) {
    decorations_[name] = decoration_node;
}

void AbstractSyntaxTreeNode::RemoveDecoration(std::string decoration_identifier) {
    auto iter = decorations_.find(decoration_identifier);
    if (iter == decorations_.end())  {
        std::stringstream concat;
        concat << "Tried to remove decoration that does not exist.  Decoration name: " << decoration_identifier;
        throw std::out_of_range(concat.str());
    }
    else {
        decorations_.erase(iter);
    }
}















