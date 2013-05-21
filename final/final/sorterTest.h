#ifndef SORTERTEST_H
#define SORTERTEST_H

#include <QObject>
#include <QtTest>
#include "sorter.h"
#include "comparator.h"
#include "IntComparator.h"
#include "doubleComparator.h"

class SorterTest : public QObject
{
    Q_OBJECT
private slots:
    void testSort1()
    {
        Sorter<int>* sorter = new Sorter<int>(new IntComparator());

        const int size = 10;
        int* array = new int[size];
        qsrand(QTime::currentTime().msec());
        for (int i = 0; i < size; i++)
            array[i] = qrand() % 10;
        sorter->sort(array, size);
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                delete sorter;
                delete[] array;
                QFAIL("Array is not sorted!");
            }
        }

        delete[] array;
        delete sorter;
    }
    void testSort2()
    {
        Sorter<double>* sorter = new Sorter<double>(new DoubleComparator());

        const int size = 5;
        double* array = new double[size];
        array[0] = 5.1;
        array[1] = 10.6;
        array[2] = 5.7;
        array[3] = 8.0;
        array[4] = 1.0;

        sorter->sort(array, size);
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                delete sorter;
                delete[] array;
                QFAIL("Array is not sorted!");
            }
        }

        delete[] array;
        delete sorter;
    }
};



#endif // SORTERTEST_H
