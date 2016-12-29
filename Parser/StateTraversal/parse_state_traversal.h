//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_PARSE_STATE_TRAVERSAL_H
#define PARSER_PARSE_STATE_TRAVERSAL_H

#include "parse_state_traversal_type.h"
#include "../grammar_rule.h"

class ParseStateTraversal {
public:
    ParseStateTraversal(ParseStateTraversalType type, GrammarRule rule);
    ParseStateTraversal(ParseStateTraversalType type, int state);

public:
    ParseStateTraversalType type() const;
    GrammarRule rule() const;
    int state() const;

private:
    ParseStateTraversalType type_;
    GrammarRule rule_;
    int state_;
};


#endif //PARSER_PARSE_STATE_TRAVERSAL_H
