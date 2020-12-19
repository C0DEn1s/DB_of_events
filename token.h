//
// Created by denis on 12.08.2020.
//

#ifndef FINAL_TOKEN_H
#define FINAL_TOKEN_H

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
    DATE,
    EVENT,
    COLUMN,
    LOGICAL_OP,
    COMPARE_OP,
    PAREN_LEFT,
    PAREN_RIGHT,
};

struct Token {
    const string value;
    const TokenType type;
};

vector<Token> Tokenize(istream& cl);

#endif //FINAL_TOKEN_H
