//
// Created by Alexander Robau on 12/15/16.
//

#include "lexer.h"


lexer::lexer(const std::string parse_filename) : filename(parse_filename) {
    std::string full_name = filename + ".parse";
    filestream = std::ifstream(full_name);

    ParsefileReader.produceLexography(filestream);
}