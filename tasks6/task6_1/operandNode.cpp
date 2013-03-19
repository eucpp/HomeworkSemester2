#include "operandNode.h"

void OperandNode::print(QTextEdit* out)
{
    QString oprndStr;
    out->append(oprndStr.number(oprnd) + QString(" "));
}

double OperandNode::calc() throw(IncorrectExprExc)
{
    return static_cast<double>(oprnd);
}
