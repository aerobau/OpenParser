//
// Created by Alexander Robau on 12/24/16.
//

#ifndef PARSER_TREE_NODE_H
#define PARSER_TREE_NODE_H


#include <memory>
#include <vector>
#include <map>
#include <string>

class AbstractSyntaxTreeNode {
public:
    AbstractSyntaxTreeNode();
    AbstractSyntaxTreeNode(std::string);

    AbstractSyntaxTreeNode* parent();
    std::size_t ChildrenCount();

    AbstractSyntaxTreeNode* GetChild(int);
    void AddChild(AbstractSyntaxTreeNode);
    void AddDecoration(std::string, AbstractSyntaxTreeNode*);
    void RemoveDecoration(std::string);
private:
    std::string name_;
    std::vector<std::unique_ptr<AbstractSyntaxTreeNode>> children_;
    AbstractSyntaxTreeNode* parent_;
    std::map<std::string, AbstractSyntaxTreeNode*> decorations_;
};


#endif //PARSER_TREE_NODE_H
