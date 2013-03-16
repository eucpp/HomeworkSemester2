#pragma once

#include "stackByHeap.h"
#include "stackTest.h"

class StackByHeapTest : public StackTest
{
    Q_OBJECT
protected:
    AbstractStack<int>* createStack()
    {
        return new StackByHeap<int>;
    }
};
