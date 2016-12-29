//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_GRAMMAR_STATE_H
#define PARSER_GRAMMAR_STATE_H


#include <vector>
#include "../grammar_rule.h"
#include "grammar_state_connection.h"

class GrammarState {
public:
    GrammarState(std::vector<GrammarRule> grammar_rules, std::vector<GrammarStateConnection> state_connections,
                 int state_number);
    GrammarState(std::vector<GrammarRule> grammer_rules, int state_number);

    void AddStateConnection(GrammarStateConnection grammar_state_connection);
    void AddGrammarRule(GrammarRule grammar_rule);

    int state_number();
private:
    const int state_number_;
    std::vector<GrammarRule> grammar_rules_;
    std::vector<GrammarStateConnection> state_connections_;
};


#endif //PARSER_GRAMMAR_STATE_H
