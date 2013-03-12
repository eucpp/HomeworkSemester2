#pragma once

#include "doubleLinkedList.h"
#include "listTest.h"

class DoubleLinkedListTest : public ListTest
{
    Q_OBJECT
public:
    AbstractList<int>* createList()
    {
        return new DoubleLinkedList<int>;
    }
};
