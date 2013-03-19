#pragma once

#include <iostream>
#include <QString>
#include "parseTreeNode.h"

/**
  * @brief Nodes of parse tree contain integer operands
  */
class OperandNode : public ParseTreeNode
{
public:
    OperandNode(int value):
        ParseTreeNode(NULL, NULL), oprnd(value) {}
    void print(QTextEdit* out);
    double calc() throw(IncorrectExprExc);
    void setOperand(int op)
    {
        oprnd = op;
    }
    int getOperand()
    {
        return oprnd;
    }
private:
    int oprnd;
};
