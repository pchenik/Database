

#ifndef FINAL_YELLOW_CONDITION_PARSER_H
#define FINAL_YELLOW_CONDITION_PARSER_H

#include "node.h"

#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);
//...
//...
void TestParseCondition();

#endif //FINAL_YELLOW_CONDITION_PARSER_H