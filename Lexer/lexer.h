//
// Created by Alexander Robau on 12/15/16.
//

#ifndef PARSER_LEXER_H
#define PARSER_LEXER_H


#include <fstream>

class lexer {
public:
    lexer(const std::string parse_filename);

private:
    std::ifstream filestream;
    std::string filename;
};


#endif //PARSER_LEXER_H
