#pragma once

#include <QObject>
#include <QString>
#include <QtTest/QtTest>
#include "hashTable.h"
#include "sumHashFunction.h"

class HashTableTest : public QObject
{
    Q_OBJECT
public:
    HashTableTest()
    {
        hash = new SumHashFunction;
    }
    ~HashTableTest()
    {
        delete hash;
    }
private:
    HashTable<int>* table;
    HashFunction* hash;
    static const unsigned int tableSize = 100;
private slots:
    void init()
    {
        table = new HashTable<int>(tableSize, hash);
    }
    void cleanup()
    {
        delete table;
    }
    void addElementTest1()
    {
        table->addElement(QString("new"), 5);
    }
    void addElementTest2()
    {
        for (unsigned int i = 0; i < tableSize + 20; i++)
        {
            QString key = QChar(i);
            table->addElement(key, i);
        }
        try
        {
            QString key2 = QChar(tableSize);
            unsigned int actual = table->getElement(key2);
            unsigned int expected = tableSize;
            QCOMPARE(actual, expected);
        }
        catch (AccessToEmptyExc*)
        {
            QFAIL("");
        }
    }


    void getElementTest1()
    {
        QString key;
        key = "five";
        table->addElement(key, 5);
        QCOMPARE(table->getElement(key), 5);
    }
    void getElementTest2()
    {
        QString key1("first");
        QString key2("second");
        QString key3("third");
        table->addElement(key1, 1);
        table->addElement(key2, 2);
        table->addElement(key3, 3);
        QCOMPARE(table->getElement(key2), 2);
    }
    void deleteElementTest()
    {
        QString key("test");
        table->addElement(key, 5);
        table->deleteElement(key);
        // exception should be thrown
        try
        {
            table->getElement(key);
            QFAIL("Exception expected");
        }
        catch (AccessToEmptyExc*)
        {}
    }
};
