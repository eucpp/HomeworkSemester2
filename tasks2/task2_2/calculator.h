#pragma once

#include <iostream>
#include <string>
#include "stackByHeap.h"
#include "stackByArray.h"
#include <math.h>
#include <exception>
#include "incorrectExprExc.h"

using std::string;


class Calculator
{
public:
    Calculator();
    ~Calculator();
    double calc(string expression) throw(IncorrectExprExc*);
    void test();
private:
    AbstractStack<char>* stack;
    string polishExpr;
    void parse(string expression) throw(IncorrectExprExc*);
    double calc(string::iterator &itr) throw(IncorrectExprExc*);
    static bool permitted(char ch);
    static bool isNumber(char ch);
    static bool isOperator(char ch);
    static int getPriority(char ch);
};
