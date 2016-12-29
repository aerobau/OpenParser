//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_GRAMMAR_STATE_CONNECTION_H
#define PARSER_GRAMMAR_STATE_CONNECTION_H

#include <string>
#include "grammar_state.h"

class GrammarStateConnection {
private:
    GrammarState* state1_;
    GrammarState* state2_;
    std::string lexigraphic_identifier_;

public:
    GrammarState* GetConnectedState(GrammarState* current_state);
    std::string lexigraphic_identifier();
};


#endif //PARSER_GRAMMAR_STATE_CONNECTION_H
