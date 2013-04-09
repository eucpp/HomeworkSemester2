#pragma once

#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        bag = new Bag<int>;
    }
    void cleanup()
    {
        delete bag;
    }
    void putTest1()
    {
        bag->put(1, 1);
    }
    void countTest()
    {
        bag->put(1, 5);
        QCOMPARE(bag->count(), static_cast<unsigned int>(5));
    }
    void putTest2()
    {
        bag->put(1, 1);
        bag->put(2, 4);
        bag->put(1, 3);
        QCOMPARE(bag->count(), static_cast<unsigned int>(8));
    }
    void searchTest()
    {
        bag->put(1, 3);
        QVERIFY(bag->search(1));
    }
    void pullTest1()
    {
        bag->put(1, 5);
        Things<int> things = bag->pull(1, 4);
        QCOMPARE(things.num, static_cast<unsigned int>(4));
        QCOMPARE(bag->count(), static_cast<unsigned int>(1));
    }
    void pullTest2()
    {
        bag->put(1, 3);
        Things<int> things = bag->pull(1, 4);
        QCOMPARE(things.num, static_cast<unsigned int>(3));
        QCOMPARE(bag->count(), static_cast<unsigned int>(0));
    }

private:
    Bag<int>* bag;
};
