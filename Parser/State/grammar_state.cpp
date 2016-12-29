//
// Created by Alexander Robau on 12/15/16.
//

#include "grammar_state.h"

// MARK: Constructors

GrammarState::GrammarState(std::vector<GrammarRule> grammar_rules,
                           std::vector<GrammarStateConnection> state_connections,
                           int state_number)
        : grammar_rules_(grammar_rules), state_connections_(state_connections), state_number_(state_number) { }

GrammarState::GrammarState(std::vector<GrammarRule> grammer_rules, int state_number)
        : grammar_rules_(grammer_rules), state_number_(state_number) { }

// MARK: Public methods

void GrammarState::AddGrammarRule(GrammarRule grammar_rule) {
    grammar_rules_.push_back(grammar_rule);
}

void GrammarState::AddStateConnection(GrammarStateConnection grammar_state_connection) {
    state_connections_.push_back(grammar_state_connection);
}

// MARK: Public accessors and mutators

int GrammarState::state_number() {
    return state_number_;
}