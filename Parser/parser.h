//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <stack>

#include "parse_table.h"
#include "AbstractSyntaxTree/abstract_syntax_tree_builder.h"

class Parser {
public:
    Parser(ParseTable parse_table, ParseTable goto_table, AbstractSyntaxTreeBuilder tree_builder);

    void Parse(std::vector<std::string> tokens);
private:
    void BuildTree(GrammarRule rule);

    ParseTable parse_table_;
    ParseTable goto_table_;
    AbstractSyntaxTreeBuilder tree_builder_;
    std::stack<int> states_stack_;
};


#endif //PARSER_PARSER_H
