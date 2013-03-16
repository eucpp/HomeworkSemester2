#pragma once

#include "stackByArray.h"
#include "stackTest.h"

class StackByArrayTest : public StackTest
{
    Q_OBJECT
protected:
    AbstractStack<int>* createStack()
    {
        return new StackByArray<int>;
    }
};
