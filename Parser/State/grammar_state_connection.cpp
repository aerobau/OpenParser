//
// Created by Alexander Robau on 12/15/16.
//

#include "grammar_state_connection.h"

GrammarState* GrammarStateConnection::GetConnectedState(GrammarState *current_state) {
    if (state1_->state_number() == current_state->state_number()) {
        return state2_;
    }
    else {
        return state1_;
    }
}

std::string GrammarStateConnection::lexigraphic_identifier() {
    return lexigraphic_identifier_;
}