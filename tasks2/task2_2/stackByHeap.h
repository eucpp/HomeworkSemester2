#pragma once

#include "../task2_1/listElement.h"
#include "abstractStack.h"

template <typename Type> class StackByHeap: public AbstractStack<Type>
{
public:
    StackByHeap(): head(NULL) {}
    StackByHeap(Type val)
    {
        push(val);
    }
    void push(Type val)
    {
        ListElement<Type>* newElem = new ListElement<Type>;
        newElem->setValue(val);
        newElem->setNext(head);
        head = newElem;
    }
    Type pop() throw(AccessToEmptyExc*)
    {
        if (isEmpty())
            throw  new AccessToEmptyExc();
        Type result = head->getValue();
        ListElement<Type>* tmp = head;
        head = head->getNext();
        tmp->setNext(NULL);
        delete tmp;
        return result;
    }
    Type top() throw(AccessToEmptyExc*)
    {
        if (isEmpty())
            throw new AccessToEmptyExc();
        return head->getValue();
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    ~StackByHeap()
    {
        delete head;
    }

private:
    ListElement<Type>* head;
};
