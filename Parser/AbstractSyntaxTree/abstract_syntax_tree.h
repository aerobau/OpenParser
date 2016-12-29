//
// Created by Alexander Robau on 12/24/16.
//

#ifndef PARSER_TREE_H
#define PARSER_TREE_H


#include <memory>
#include "abstract_syntax_tree_node.h"

class AbstractSyntaxTree {
public:
    class PreorderIterator {
    public:

    private:

    };

    class PostorderIterator {
    public:

    private:

    };

    PreorderIterator PreorderBegin();
    PreorderIterator PreorderEnd();
    PostorderIterator PostorderEnd()
    PostorderIterator PostorderBegin();

    AbstractSyntaxTreeNode* GetNode(std::vector<int>);
    AbstractSyntaxTreeNode* GetNodePreOrderLocation(int);
    AbstractSyntaxTreeNode* GetNodePostOrderLocation(int);
    AbstractSyntaxTreeNode* root();
private:
    std::unique_ptr<AbstractSyntaxTreeNode> root_;
};


#endif //PARSER_TREE_H
