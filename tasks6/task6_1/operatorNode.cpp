#include "operatorNode.h"

void OperatorNode::print(QTextEdit *out)
{
    out->append(oprt + QString(" "));
    this->leftChild->print(out);
    this->rightChild->print(out);
}
double OperatorNode::calc() throw(IncorrectExprExc)
{
    double operand1 = this->leftChild->calc();
    double operand2 = this->rightChild->calc();
    switch (oprt.toAscii())
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
        if (operand2 == 0)
    case '/':
            throw IncorrectExprExc("Division by zero");
        return operand1 / operand2;
    }
}
