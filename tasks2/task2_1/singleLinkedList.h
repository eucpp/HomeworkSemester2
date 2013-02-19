#pragma once

#include "abstractList.h"

template <typename Type> class SingleLinkedList : public AbstractList<Type>
{
public:
    SingleLinkedList()
    {
        this->headElem = NULL;
        this->currentElem = NULL;
        this->elemCount = 0;
    }
    SingleLinkedList(Type val)
    {
        this->headElem = new ListElement<Type>();
        this->headElem->setValue(val);
        this->currentElem = this->headElem;
        this->elemCount++;
    }
    void prev()
    {
        if (this->isEmpty() || this->currentElem == this->headElem)
            return;
        ListElement<Type>* tmp = this->headElem;
        while (tmp->getNext() != this->currentElem)
            tmp = tmp->getNext();
        this->currentElem = tmp;
    }
    void addElement(Type val)
    {
        ListElement<Type>* newElem = new ListElement<Type>();
        newElem->setValue(val);
        ListElement<Type>* tmp = NULL;
        if (this->currentElem == this->headElem)
        {
            tmp = this->headElem;
            newElem->setNext(this->headElem);
            this->headElem = newElem;
            this->currentElem = this->headElem;
        }
        else
        {
            tmp = this->currentElem;
            newElem->setNext(tmp);
            prev();
            this->currentElem->setNext(newElem);
            this->next();
        }
        this->elemCount++;
    }
    void removeElement()
    {
        if (this->isEmpty())
            return;
        if (this->currentElem == this->headElem)
        {
            ListElement<Type>* tmp = this->currentElem->getNext();
            this->headElem->setNext(NULL);
            delete this->headElem;
            this->headElem = tmp;
            this->currentElem = this->headElem;
        }
        else
        {
            prev();
            ListElement<Type>* prevElem = this->currentElem;
            this->next();
            ListElement<Type>* nextElem = this->currentElem->getNext();
            this->currentElem->setNext(NULL);
            delete this->currentElem;
            this->currentElem = prevElem;
            this->currentElem->setNext(nextElem);
        }
        this->elemCount--;
    }
    ~SingleLinkedList()
    {
        delete this->headElem;
    }
};

