#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "abstractList.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    ListTest() {}
    virtual ~ListTest() {}
    virtual AbstractList<int>* createList() = 0;
private:
    AbstractList<int>* list;
private slots:
    void init()
    {
        list = createList();
    }
    void cleanup()
    {
        delete list;
    }
    void addElementTest()
    {
        list->addElement(6);
    }
    void currentTest()
    {
        list->addElement(6);
        QCOMPARE(list->current(), 6);
    }
    void currentKeyTest()
    {
        list->addElement(5, QString("key"));
        QCOMPARE(list->currentKey(), QString("key"));
    }
    void countTest()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        QCOMPARE(list->count(), 3);
    }
    void isEmptyTest1()
    {
        QVERIFY(list->isEmpty() == true);
    }
    void isEmptyTest2()
    {
        list->addElement(1);
        QVERIFY(list->isEmpty() == false);
    }
    void isEOLTest()
    {
        QVERIFY(list->isEOL() == true);
    }
    void isEOLTest2()
    {
        list->addElement(4);
        QVERIFY(list->isEOL() == false);
    }
    void nextTest()
    {
        list->addElement(1);
        list->addElement(2);
        list->next();
        QCOMPARE(list->current(), 1);
    }
    void headTest()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->next();
        list->next();
        list->head();
        QCOMPARE(list->current(), 3);
    }
    void prevTest()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->next();
        list->next();
        list->prev();
        QCOMPARE(list->current(), 2);
    }
    void removeElementTest1()
    {
        list->addElement(4);
        list->removeElement();
        QVERIFY(list->isEmpty() == true);
    }
    void removeElementTest2()
    {
        list->addElement(1);
        list->addElement(2);
        list->addElement(3);
        list->next();
        list->removeElement();
        QCOMPARE(list->current(), 3);
    }
};


