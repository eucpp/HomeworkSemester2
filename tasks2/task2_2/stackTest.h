#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "abstractStack.h"

class StackTest : public QObject
{
    Q_OBJECT
public:
    StackTest() {}
    virtual ~StackTest() {}
//protected:
    virtual AbstractStack<int>* createStack() = 0;
private slots:
    void init()
    {
        stack = createStack();
    }
    void cleanup()
    {
        delete stack;
    }
    void pushTest()
    {
        stack->push(5);
    }
    void popTest()
    {
        stack->push(5);
        QCOMPARE(stack->pop(), 5);
    }
    void popTest2()
    {
        stack->push(1);
        stack->push(2);
        stack->push(3);
        stack->pop();
        stack->pop();
        QCOMPARE(stack->pop(), 1);
    }
    void popTest3()
    {
        try
        {
            int val = stack->pop();
            Q_UNUSED(val);
            QFAIL("");
        }
        catch (AccessToEmptyExc* exc)
        {}
    }

    void topTest()
    {
        stack->push(5);
        QCOMPARE(stack->top(), 5);
    }
    void isEmptyTest()
    {
        QVERIFY(stack->isEmpty());
    }
    void isEmptyTest2()
    {
        stack->push(1);
        QVERIFY(!stack->isEmpty());
    }


private:
    AbstractStack<int>* stack;
};
