#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include "operandNode.h"
#include "operatorNode.h"
#include "../../tasks2/task2_2/incorrectExprExc.h"

class ParseTree
{
public:
    ParseTree();
    ~ParseTree();
    void parse(QString filename) throw(IncorrectExprExc);
    double calc();
    void print(QTextEdit* out);
private:
    void parse(std::ifstream&, ParseTreeNode*& currNode) throw(IncorrectExprExc);
    ParseTreeNode* root;
};
