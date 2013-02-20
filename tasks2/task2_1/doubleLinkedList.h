#pragma once

#include "abstractList.h"

template <typename Type> class DoubleLinkedList: public AbstractList<Type>
{
public:
    DoubleLinkedList()
    {
        this->headElem = NULL;
        this->currentElem = NULL;
        this->elemCount = 0;
    }
    DoubleLinkedList(Type val)
    {
        this->headElem = new ListElement<Type>(val);
        this->currentElem = this->headElem;
        this->elemCount++;
    }
    void prev()
    {
        if (this->isEmpty() || this->currentElem == NULL)
            return;
        this->currentElem = this->currentElem->getPrev();
    }
    void addElement(Type val)
    {
        ListElement<Type>* newElem = new ListElement<Type>(val);
        if (this->currentElem == this->headElem)
        {
            newElem->setNext(this->headElem);
            if (this->headElem != NULL)
            {
                this->headElem->setPrev(newElem);
            }
            this->headElem = newElem;
            this->currentElem = this->headElem;
        }
        else
        {
            if (this->currentElem == NULL)
                return;
            newElem->setNext(this->currentElem);
            prev();
            this->currentElem->setNext(newElem);
            newElem->setPrev(this->currentElem);
            this->next();
            if (this->currentElem->getNext() != NULL)
            {
                this->next();
                this->currentElem->setPrev(newElem);
                prev();
            }
        }
        this->elemCount++;
    }
    void removeElement()
    {
        if (this->isEmpty() || this->currentElem == NULL)
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
            if (nextElem != NULL)
            {
                nextElem->setPrev(this->currentElem);
            }
        }
        this->elemCount--;
    }
    ~DoubleLinkedList()
    {
        delete this->headElem;
    }
};
