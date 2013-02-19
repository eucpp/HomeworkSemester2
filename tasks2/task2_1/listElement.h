#pragma once

#include <iostream>


template <typename Type> class ListElement
{
public:
    ListElement(): value(0), next(NULL) {}
    ListElement(Type val): value(val), next(NULL) {}
    ListElement(Type val, ListElement<Type>* nextElem): value(val), next(nextElem) {}
    void setValue(Type val)
    {
        value = val;
    }
    Type getValue()
    {
        return value;
    }
    void setNext(ListElement<Type>* nextElem)
    {
        next = nextElem;
    }
    ListElement<Type>* getNext()
    {
        return next;
    }
    ~ListElement()
    {
        delete next;
    }
private:
    Type value;
    ListElement<Type>* next;
};

