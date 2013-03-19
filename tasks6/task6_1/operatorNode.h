#pragma once

#include <iostream>
#include <QChar>
#include "parseTreeNode.h"

/**
  * @brief Class of nodes of parse tree which contains the math operators
  */
class OperatorNode : public ParseTreeNode
{
public:
    OperatorNode(ParseTreeNode* lChild, ParseTreeNode* rChild, QChar op):
        ParseTreeNode(lChild, rChild), oprt(op) {}
    void print(QTextEdit* out);
    double calc() throw(IncorrectExprExc);
    void setOperator(QChar op)
    {
        oprt = op;
    }
    QChar getOperator()
    {
        return oprt;
    }
private:
    QChar oprt;
};
