//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_GRAMMAR_RULE_H
#define PARSER_GRAMMAR_RULE_H


#include <string>
#include <vector>

struct GrammarRule {
    std::string identifier;
    std::vector<std::string> components;
    bool builds_tree;
};


#endif //PARSER_GRAMMAR_RULE_H
