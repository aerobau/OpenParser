//
// Created by Alexander Robau on 12/15/16.
//

#include "parse_state_traversal.h"

// MARK: Constructors

ParseStateTraversal::ParseStateTraversal(ParseStateTraversalType type, GrammarRule rule) : type_(type), rule_(rule) { }

ParseStateTraversal::ParseStateTraversal(ParseStateTraversalType type, int state) : type_(type), state_(state) { }

ParseStateTraversalType ParseStateTraversal::type() const {
    return type_;
}

GrammarRule ParseStateTraversal::rule() const {
    return rule_;
}

int ParseStateTraversal::state() const {
    return state_;
}