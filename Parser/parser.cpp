//
// Created by Alexander Robau on 12/15/16.
//

#include <iostream>
#include "parser.h"

Parser::Parser(ParseTable parse_table, ParseTable goto_table, AbstractSyntaxTreeBuilder tree_builder)
        : parse_table_(parse_table), tree_builder_(tree_builder), goto_table_(goto_table) {
    states_stack_ = std::stack<int>();
}

// MARK: PUBLIC FUNCTIONS

void Parser::Parse(std::vector<std::string> tokens) {
    for (std::string token : tokens) {
        ParseStateTraversal traversal = parse_table_.GetTableEntry(token, states_stack_.top());
        switch (traversal.type()) {
            case SHIFT:
                states_stack_.push(traversal.state());

            case REDUCE:
                states_stack_.pop();
                traversal = goto_table_.GetTableEntry(traversal.rule().identifier, states_stack_.top());
                while (traversal.type() == INVALID) {
                    states_stack_.pop();
                    traversal = goto_table_.GetTableEntry(traversal.rule().identifier, states_stack_.top());
                }
                states_stack_.push(traversal.state());
                if (traversal.rule().builds_tree) {
                    BuildTree(traversal.rule());
                }

            case INVALID: throw std::out_of_range("Got an invalid traversal for a token");
        }
    }
}

// MARK: PRIVATE FUNCTIONS

void Parser::BuildTree(GrammarRule rule) {
    // TODO implement
}