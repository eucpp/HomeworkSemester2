#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        set = new Set<int>;
    }
    void cleanup()
    {
        delete set;
    }
    void addElementTest()
    {
        set->addElement(1);
    }
    void deleteElementTest()
    {
        set->addElement(1);
        set->deleteElement(1);
    }
    void hasTest1()
    {
        set->addElement(5);
        QVERIFY(set->has(5));
    }
    void hasTest2()
    {
        set->addElement(5);
        set->deleteElement(5);
        QVERIFY(!set->has(5));
    }
    void operatorEqualTest()
    {
        Set<int>* set2 = new Set<int>;
        set->addElement(1);
        set2->addElement(1);
        set->addElement(2);
        set2->addElement(2);
        QVERIFY(*set == *set2);
        delete set2;
    }
    void unionSetsTest()
    {
        Set<int>* set2 = new Set<int>;
        Set<int>* expectedSet = new Set<int>;
        set->addElement(1);
        set2->addElement(2);
        set2->addElement(3);
        expectedSet->addElement(1);
        expectedSet->addElement(2);
        expectedSet->addElement(3);
        QVERIFY(*Set<int>::unionSets(set, set2) == *expectedSet);
        delete set2;
        delete expectedSet;
    }
    void intersectionSetsTest()
    {
        Set<int>* set2 = new Set<int>;
        Set<int>* expectedSet = new Set<int>;
        set->addElement(1);
        set2->addElement(1);
        set2->addElement(2);
        expectedSet->addElement(1);
        QVERIFY(*Set<int>::intersectionSets(set, set2) == *expectedSet);
        delete set2;
        delete expectedSet;
    }

private:
    Set<int>* set;
};
