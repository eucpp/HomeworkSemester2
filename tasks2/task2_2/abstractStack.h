#pragma once
#include "../task2_1/accessToEmptyExc.h"

template <typename Type> class AbstractStack
{
public:
    virtual void push(Type val) = 0;
    virtual Type pop() throw(AccessToEmptyExc*) = 0;
    virtual Type top() throw(AccessToEmptyExc*) = 0;
    virtual bool isEmpty() = 0;
    virtual ~AbstractStack() {}
};
