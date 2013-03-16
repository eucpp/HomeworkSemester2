#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "quickSortSorter.h"
#include "sorterTest.h"

class QuickSorterTest : public SorterTest
{
    Q_OBJECT
public:
    Sorter<int>* createSorter()
    {
        return new QuickSortSorter<int>;
    }
};
