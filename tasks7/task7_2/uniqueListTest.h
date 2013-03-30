#pragma once

#include "../../tasks2/task2_1/listTest.h"
#include "uniqueList.h"

class UniqueListTest : public ListTest
{
    Q_OBJECT
public:
    UniqueListTest() {}
    ~UniqueListTest() {}
    AbstractList<int>* createList()
    {
        return new UniqueList<int>;
    }
private slots:
    void addElementTest2()
    {
        list->addElement(1);
        try
        {
            list->addElement(1);
            QFAIL("");
        }
        catch (AddExistedExc* exc)
        {}
    }

};
