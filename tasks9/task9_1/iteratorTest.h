#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "../../tasks8/task8_1/bag.h"
#include "iterator.h"
#include "avlTreeIterator.h"

class IteratorTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        bag = new Bag<int>();
        bag->put(1, 3);
        bag->put(2);
        bag->put(3);
        iter = bag->iterator();
    }
    void cleanup()
    {
        delete bag;
        delete iter;
    }
    void nextTest1()
    {
           iter->next();
    }
    // check are the same elements placed one by one
    void nextTest2()
    {
        while (iter->next() != 1);
        QCOMPARE(iter->next(), 1);
        QCOMPARE(iter->next(), 1);
    }
    void hasNextTest()
    {
        QVERIFY(iter->hasNext());
        for (int i = 0; i < bag->count(); i++)
            iter->next();
        QVERIFY(!iter->hasNext());
    }
    void addTest()
    {
        iter->add(4);
        QVERIFY(bag->search(4));
    }
    void removeTest()
    {
        while (iter->hasNext())
            iter->remove();
        QVERIFY(!bag->search(1));
        QVERIFY(!bag->search(2));
        QVERIFY(!bag->search(3));
    }

private:
    Bag<int>* bag;
    Iterator<int>* iter;
};
