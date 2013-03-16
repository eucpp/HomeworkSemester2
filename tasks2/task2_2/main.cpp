#include <iostream>
#include <QObject>
#include <QtTest>
#include "stackByHeap.h"
#include "stackByArray.h"
#include "calculator.h"
#include "stackByHeapTest.h"
#include "stackByArrayTest.h"
#include <exception>
#include "../task2_1/accessToEmptyExc.h"

using namespace std;

void stackIsEmpty(AbstractStack<int>* stack)
{
    cout << "Now stack ";
    if (stack->isEmpty())
        cout << "is empty";
    else
        cout << "isn't empty";
    cout << endl;
}

void stackTest()
{
    cout << "Stack test:" << endl;
    AbstractStack<int>* stack = new StackByArray<int>;
    stackIsEmpty(stack);

    const int iter = 12;
    for (int i = 0; i < iter; ++i)
    {
        cout << "Enter value ";
        int val;
        cin >> val;
        cout << " push " << val << endl;
        stack->push(val);
    }
    stackIsEmpty(stack);
    for (int i = 0; i < iter; ++i)
    {
        cout << "Top element: " << stack->top() << endl;
        cout << "Pop element: " << stack->pop() << endl;
    }
    stackIsEmpty(stack);
    delete stack;
}

int main()
{
    StackTest* stackTest1 = new StackByHeapTest();
    QTest::qExec(stackTest1);
    StackTest* stackTest2 = new StackByArrayTest();
    QTest::qExec(stackTest2);

    Calculator* calc = new Calculator;
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
        int value = calc->calc(expr);
        cout << "Value of expression: " << value << endl;
    }
    catch (std::exception* e)
    {
        cout << e->what() << endl;
    }

    delete calc;
    return 0;
}

