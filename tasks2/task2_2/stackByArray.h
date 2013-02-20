#pragma once

#include "abstractStack.h"

template <typename Type> class StackByArray : public AbstractStack<Type>
{
public:
    StackByArray()
    {
        currMaxInd = addInd;
        array = new Type[currMaxInd];
        current = 0;
    }
    ~StackByArray()
    {
        delete[] array;
    }
    void push(Type val)
    {
        if (!isFull())
            array[current++] = val;
        else
        {
            Type* newArray = new Type[currMaxInd + addInd];
            copy(newArray, array, currMaxInd);
            delete[] array;
            array = newArray;
            array[current++] = val;
        }
    }
    Type pop() throw(int)
    {
        if (isEmpty())
            throw 1;
        return array[--current];
    }
    Type top() throw(int)
    {
        if (isEmpty())
            throw 1;
        return array[current - 1];
    }
    bool isEmpty()
    {
        return (current == 0);
    }
private:
    Type* array;
    int current;
    int currMaxInd;
    static const int addInd = 10;
    bool isFull()
    {
        return (current == currMaxInd);
    }
    void copy(Type* dest, Type* src, int size)
    {
        for (int i = 0; i < size; i++)
            dest[i] = src[i];
    }
};


