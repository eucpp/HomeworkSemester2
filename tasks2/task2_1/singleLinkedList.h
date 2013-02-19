#pragma once

#include "abstractList.h"

template <typename Type> class SingleLinkedList : public AbstractList<Type>
{
public:
    SingleLinkedList(): headElem(NULL), currentElem(NULL), elemCount(0) {}
    SingleLinkedList(Type val)
    {
        headElem = new ListElement<Type>();
        headElem->setValue(val);
        currentElem = headElem;
        elemCount++;
    }
    void next()
    {
        if (isEmpty() || currentElem == NULL)
            return;
        currentElem = currentElem->getNext();
    }
    void prev()
    {
        if (isEmpty() || currentElem == headElem)
            return;
        ListElement<Type>* tmp = headElem;
        while (tmp->getNext() != currentElem)
            tmp = tmp->getNext();
        currentElem = tmp;
    }
    void head()
    {
        currentElem = headElem;
    }
    Type current() throw(int)
    {
        if (currentElem == NULL)
            throw 1;
        return currentElem->getValue();
    }
    int count()
    {
        return elemCount;
    }
    bool isEmpty()
    {
        return (count() == 0);
    }
    bool isEOL()
    {
        return (currentElem == NULL);
    }
    void addElement(Type val)
    {
        ListElement<Type>* newElem = new ListElement<Type>();
        newElem->setValue(val);
        ListElement<Type>* tmp = NULL;
        if (currentElem == headElem)
        {
            tmp = headElem;
            newElem->setNext(headElem);
            headElem = newElem;
            currentElem = headElem;
        }
        else
        {
            tmp = currentElem;
            newElem->setNext(tmp);
            prev();
            currentElem->setNext(newElem);
            next();
        }
        elemCount++;
    }
    void removeElement()
    {
        if (isEmpty())
            return;
        if (currentElem == headElem)
        {
            ListElement<Type>* tmp = currentElem->getNext();
            headElem->setNext(NULL);
            delete headElem;
            headElem = tmp;
            currentElem = headElem;
        }
        else
        {
            prev();
            ListElement<Type>* prevElem = currentElem;
            next();
            ListElement<Type>* nextElem = currentElem->getNext();
            currentElem->setNext(NULL);
            delete currentElem;
            currentElem = prevElem;
            currentElem->setNext(nextElem);
        }
        elemCount--;
    }
    ~SingleLinkedList()
    {
        delete headElem;
    }
private:
    ListElement<Type>* headElem;
    ListElement<Type>* currentElem;
    int elemCount;
};

