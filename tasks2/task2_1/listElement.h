#pragma once

#include <iostream>
#include <QString>


template <typename Type> class ListElement
{
public:
    ListElement(): value(0), next(NULL), prev(NULL) {}
    ListElement(Type val): value(val), next(NULL), prev(NULL) {}
    ListElement(Type val, ListElement<Type>* nextElem): value(val), next(nextElem), prev(NULL) {}
    ListElement(Type val, ListElement<Type>* nextElem, ListElement<Type>* prevElem):
        value(val), next(nextElem), prev(prevElem) {}
    ListElement(ListElement<Type>& copy): value(copy.getValue()), key(copy.getKey()),
        next(copy.getNext()), prev(copy.getPrev()){}

    void setValue(Type val)
    {
        value = val;
    }
    void setKey(QString newKey)
    {
        key = newKey;
    }
    Type getValue()
    {
        return value;
    }
    QString getKey()
    {
        return key;
    }
    void setNext(ListElement<Type>* nextElem)
    {
        next = nextElem;
    }
    ListElement<Type>* getNext()
    {
        return next;
    }
    void setPrev(ListElement<Type>* prevElem)
    {
        prev = prevElem;
    }
    ListElement<Type>* getPrev()
    {
        return prev;
    }
    ~ListElement()
    {
        if (next != NULL)
            delete next;
    }
private:
    Type value;
    QString key;
    ListElement<Type>* next;
    ListElement<Type>* prev;
};

