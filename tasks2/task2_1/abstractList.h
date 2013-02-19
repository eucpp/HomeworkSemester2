#pragma once

#include "listElement.h"

template <typename Type> class AbstractList
{
protected:
    ListElement<Type>* headElem;
    ListElement<Type>* currentElem;
    int elemCount;
public:
    void next()
    {
        if (isEmpty() || currentElem == NULL)
            return;
        currentElem = currentElem->getNext();
    }
    virtual void prev() = 0;
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
    // return true if next list element is NULL
    bool isEOL()
    {
        return (currentElem == NULL);
    }
    // add new element before current
    virtual void addElement(Type val) = 0;
    // remove current element
    virtual void removeElement() = 0;
};
