#pragma once

#include "../../tasks2/task2_1/singleLinkedList.h"
#include "addExistedExc.h"

template <typename Type> class UniqueList : public SingleLinkedList<Type>
{
public:
    void addElement(Type val) throw(AddExistedExc*);
};

template <typename Type>
void UniqueList<Type>::addElement(Type val) throw(AddExistedExc*)
{
    {
        if (this->exist(val))
            throw new AddExistedExc;
        SingleLinkedList<Type>::addElement(val);
    }
}

