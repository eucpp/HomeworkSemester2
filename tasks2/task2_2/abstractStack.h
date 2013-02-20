#pragma once

template <typename Type> class AbstractStack
{
public:
    virtual void push(Type val) = 0;
    virtual Type pop() throw(int) = 0;
    virtual Type top() throw(int) = 0;
    virtual bool isEmpty() = 0;
};
