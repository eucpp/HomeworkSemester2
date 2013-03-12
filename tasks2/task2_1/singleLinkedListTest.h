#pragma once

#include "singleLinkedList.h"
#include "listTest.h"

class SingleLinkedListTest : public ListTest
{
    Q_OBJECT
public:
    AbstractList<int>* createList()
    {
        return new SingleLinkedList<int>;
    }
};
