#pragma once

#include <stdlib.h>
#include <QObject>
#include <QtTest/QtTest>
#include "sorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    SorterTest() {}
    virtual ~SorterTest() {}
    virtual Sorter<int>* createSorter() = 0;
private:
    bool isSorted(int* array, const int size)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            if (array[i] > array[i + 1])
                return false;
        }
        return true;
    }

    Sorter<int>* sorter;
private slots:
    void init()
    {
        sorter = createSorter();
    }
    void cleanup()
    {
        delete sorter;
    }
    void randomSortTest()
    {
        const int arraySize = 10;
        int* array = new int[arraySize];
        srand(time(0));
        for (int i = 0; i < arraySize; i++)
        {
            array[i] = rand() % 10;
        }
        sorter->sort(array, arraySize);
        QVERIFY(isSorted(array, arraySize));
    }
    void constSortTest()
    {
        const int arraySize = 10;
        int* array = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
            array[i] = 0;
        sorter->sort(array, arraySize);
        QVERIFY(isSorted(array, arraySize));
    }
    void reverseSortTest()
    {
        const int arraySize = 10;
        int* array = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
            array[i] = arraySize - i;
        sorter->sort(array, arraySize);
        QVERIFY(isSorted(array, arraySize));
    }

};

