#pragma once

#include <QtTest/QtTest>
#include "avlTree.h"

class AVLTreeTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        tree = new AVLTree<int>;
    }
    void cleanup()
    {
        delete tree;
    }

    // check LL balance
    void addValueTest1()
    {
        tree->addValue(4);
        tree->addValue(3);
        tree->addValue(2);
        tree->addValue(1);
        QVERIFY(tree->checkBalance());
    }
    // check LR balance
    void addValueTest2()
    {
        tree->addValue(7);
        tree->addValue(3);
        tree->addValue(8);
        tree->addValue(1);
        tree->addValue(6);
        tree->addValue(5);
        QVERIFY(tree->checkBalance());
    }
    // check RL balance
    void addValueTest3()
    {
        tree->addValue(1);
        tree->addValue(0);
        tree->addValue(5);
        tree->addValue(3);
        tree->addValue(6);
        tree->addValue(2);
        tree->addValue(4);
        QVERIFY(tree->checkBalance());
    }
    // check RR balance
    void addValueTest4()
    {
        tree->addValue(1);
        tree->addValue(2);
        tree->addValue(3);
        tree->addValue(4);
        QVERIFY(tree->checkBalance());
    }
    // just check balance
    void addValueTest5()
    {
        tree->addValue(1);
        tree->addValue(3);
        tree->addValue(4);
        tree->addValue(5);
        tree->addValue(9);
        tree->addValue(10);
        tree->addValue(12);
        QVERIFY(tree->checkBalance());
    }
    void elemNumTest()
    {
        tree->addValue(3);
        QCOMPARE(tree->elemNum(3), static_cast<unsigned int>(1));
    }

    // check the adding of equals elements
    void addEqualsTest()
    {
        tree->addValue(1);
        tree->addValue(1);
        tree->addValue(1);
        tree->addValue(1);
        QCOMPARE(tree->elemNum(1), static_cast<unsigned int>(4));
    }
    void removeEqualsTest()
    {
        tree->addValue(1);
        tree->addValue(1);
        tree->addValue(1);
        tree->removeValue(1);
        QCOMPARE(tree->elemNum(1), static_cast<unsigned int>(2));
    }

    // check balance after removing
    void removeValueTest()
    {
        tree->addValue(5);
        tree->addValue(2);
        tree->addValue(6);
        tree->addValue(3);
        tree->removeValue(6);
        QVERIFY(tree->checkBalance());
    }

private:
    AVLTree<int>* tree;
};

