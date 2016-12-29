//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_PARSETABLE_H
#define PARSER_PARSETABLE_H

#include "StateTraversal/parse_state_traversal.h"
#include <vector>
#include <map>
#include <string>

class ParseTable {
public:
    ParseTable(std::vector<std::string> tokens, int states_count);

    void SetTableEntry(ParseStateTraversal traversal, std::string token, int state);
    ParseStateTraversal GetTableEntry(std::string token, int state);
private:
    std::map<std::string, std::vector<ParseStateTraversal>> parsing_table_;
};


#endif //PARSER_PARSETABLE_H
