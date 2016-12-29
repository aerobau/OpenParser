//
// Created by Alexander Robau on 12/15/16.
//

#include "parse_table.h"

#include <assert.h>

ParseTable::ParseTable(std::vector<std::string> tokens, int states_count) {
    std::assert(states_count > 0);
    for (std::string token : tokens) {
        parsing_table_[token] = std::vector<ParseStateTraversal>((unsigned long)states_count);
    }
}

ParseStateTraversal ParseTable::GetTableEntry(std::string token, int state) {
    return parsing_table_[token][state];
}