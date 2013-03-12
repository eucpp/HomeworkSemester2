#pragma once


#include <QString>
#include "accessToEmptyExc.h"
#include "listElement.h"

template <typename Type> class AbstractList
{
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
    Type current() throw(AccessToEmptyExc*)
    {
        if (currentElem == NULL)
            throw new AccessToEmptyExc();
        return currentElem->getValue();
    }
    QString currentKey() throw(AccessToEmptyExc*)
    {
        if (currentElem == NULL)
            throw new AccessToEmptyExc();
        return currentElem->getKey();
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
    void addElement(Type val, QString key)
    {
        addElement(val);
        currentElem->setKey(key);
    }
    // remove current element
    virtual void removeElement() = 0;
    virtual ~AbstractList() {}
protected:
    ListElement<Type>* headElem;
    ListElement<Type>* currentElem;
    int elemCount;
};
