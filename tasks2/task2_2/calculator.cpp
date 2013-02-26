#include "calculator.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int tableSize = 4;
const char priorityTable[tableSize] = {'+', '-', '*', '/'};

bool isNumber(char ch)
{
    return (ch >= '0') && (ch <= '9');
}
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch =='/');
}
bool permitted(char ch)
{
    return (isNumber(ch) || ch == '(' || ch == ')' || isOperator(ch) || ch == ' ');
}
int getPriority(char ch)
{
    for (int i = 0; i < tableSize; ++i)
        if (ch== priorityTable[i])
            return i;
    return -1;
}


Calculator::Calculator()
{
    stack = new StackByHeap<char>;
    polishExpr = "";
}
Calculator::~Calculator()
{
    delete stack;
}
double Calculator::calc(string expression) throw(IncorrectExprExc*)
{
    parse(expression);
    string::iterator itr = polishExpr.end();
    --itr;
    return calc(itr);
}
double Calculator::calc(string::iterator &itr) throw(IncorrectExprExc*)
{
    char ch = *itr;
    if (::isOperator(ch))
    {
        if (itr == polishExpr.begin())
            throw new IncorrectExprExc("incorrect sequence of operators");
        double operandR = calc(--itr);
        double operandL = calc(itr);
        switch(ch)
        {
        case '+':
            return operandL + operandR;
            break;
        case '-':
            return operandL - operandR;
            break;
        case '*':
            return operandL * operandR;
            break;
        case '/':
            if (operandR == 0)
                throw new IncorrectExprExc("dividing by zero");
            return operandL / operandR;
            break;
        }
    }
    else if (::isNumber(ch))
    {
        --itr;
        return static_cast<double>(ch - '0');
    }
    else if (ch == ')')
    {
        if (itr == polishExpr.begin())
            throw new IncorrectExprExc("incorrect sequence of operators");
        --itr;
        double result = 0;
        int digit = 0;
        char num = *itr;
        while (num != '(')
        {
            result += static_cast<double>(num - '0') * pow(10.0, digit);
            digit++;
            if (itr == polishExpr.begin())
                throw new IncorrectExprExc("incorrect sequence of operators");
            --itr;
            num = *itr;
        }
        --itr;
        return result;
    }
}
void Calculator::parse(string expression) throw(IncorrectExprExc*)
{
    int balance = 0;
    for (string::iterator itr = expression.begin(); itr != expression.end(); ++itr)
    {
        char ch = *itr;
        if (!::permitted(ch))
            throw new IncorrectExprExc("invalid characters");
        if (ch == ' ')
            continue;
        else if (::isNumber(ch))
        {
            if (::isNumber(*(itr + 1)))
            {
                polishExpr += '(';
                polishExpr += ch;
                ch = *(++itr);
                polishExpr += ch;
                while (::isNumber(*(itr + 1)))
                {
                    ch = *(++itr);
                    polishExpr += ch;
                }
                polishExpr += ')';
            }
            else
                polishExpr += *itr;
        }
        else  if (ch == '(')
            {
                stack->push(ch);
                balance++;
            }
        else if (ch == ')')
        {
            balance--;
            if (balance < 0)
                throw new IncorrectExprExc("balance of brackets was broken");
            char oper = stack->pop();
            while (oper != '(')
            {
                polishExpr += oper;
                oper = stack->pop();
            }
        }
        else
        {
            int priority = ::getPriority(ch);
            if (!stack->isEmpty())
            {
                char opr = stack->top();
                while (!stack->isEmpty() && (opr != '(') && (priority <= ::getPriority(opr)))
                {
                    polishExpr += stack->pop();
                    try
                    {
                        opr = stack->top();
                    }
                    catch (std::exception* e)
                    {
                        break;
                    }
                }
            }
            stack->push(ch);
        }
    }
    while (!stack->isEmpty())
    {
        polishExpr += stack->pop();
    }
}

void Calculator::test()
{
    cout << "Calculator test:" << endl;
    cout << "Parse test:" << endl;
    cout << "Enter expression: " << endl;
    string expr;
    char ch = ' ';
    while (ch != '\n')
    {
        expr += ch;
        cin.get(ch);
    }
    cout << endl;

    try
    {
        parse(expr);
        cout << "Reverse polish expression:" << endl;
        cout << polishExpr << endl;
    }
    catch (int e)
    {
        cout << "Incorrect expression, error code " << e << endl;
    }
    string::iterator itr = polishExpr.begin();
    cout << *itr << endl;

    polishExpr = "";
    cout << "Calc test:" << endl;
    cout << "Value of expression: " << calc(expr) << endl;
}
