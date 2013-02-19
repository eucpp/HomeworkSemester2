#pragma once

#include "listElement.h"

template <typename Type> class AbstractList
{
public:
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void head() = 0;
    virtual Type current() = 0;
    virtual int count() = 0;
    virtual bool isEmpty() = 0;
    // return true if next list element is NULL
    virtual bool isEOL() = 0;
    // add new element before current
    virtual void addElement(Type val) = 0;
    // remove current element
    virtual void removeElement() = 0;
};
