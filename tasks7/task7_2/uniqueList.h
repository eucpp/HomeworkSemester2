#pragma once

#include "../../tasks2/task2_1/singleLinkedList.h"
#include "addExistedExc.h"

template <typename Type> class UniqueList : public SingleLinkedList<Type>
{
public:
    void addElement(Type val) throw(AddExistedExc*)
    {
        if (this->exist(val))
            throw new AddExistedExc;
        ListElement<Type>* newElem = new ListElement<Type>(val);
        if (this->currentElem == this->headElem)
        {
            newElem->setNext(this->headElem);
            this->headElem = newElem;
            this->currentElem = this->headElem;
        }
        else
        {
            newElem->setNext(this->currentElem);
            this->prev();
            this->currentElem->setNext(newElem);
            this->next();
        }
        this->elemCount++;
    }
};

