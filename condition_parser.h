//
// Created by denis on 12.08.2020.
//

#ifndef FINAL_CONDITION_PARSER_H
#define FINAL_CONDITION_PARSER_H

#include "node.h"
#include "token.h"
#include "date.h"
#include "test_runner.h"
#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();

#endif //FINAL_CONDITION_PARSER_H
