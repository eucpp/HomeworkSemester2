#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "bsTree.h"

class BSTreeTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        tree = new BSTree<int>;
    }
    void cleanup()
    {
        delete tree;
    }
    void addValueTest()
    {
        tree->addValue(5);
    }
    void valueExistTest1()
    {
        tree->addValue(1);
        QVERIFY(tree->valueExist(1));
    }
    void valueExistTest2()
    {
        tree->addValue(1);
        tree->addValue(2);
        tree->addValue(3);
        tree->addValue(0);
        QVERIFY(tree->valueExist(3));
    }
    void removeValueTest1()
    {
        tree->addValue(4);
        tree->removeValue(4);
    }
    void removeValueTest2()
    {
        tree->addValue(2);
        tree->removeValue(2);
        QVERIFY(!tree->valueExist(2));
    }
    void removeValueTest3()
    {
        tree->addValue(5);
        tree->addValue(7);
        tree->addValue(6);
        tree->addValue(8);
        tree->removeValue(6);
        QVERIFY(tree->valueExist(8));
    }

private:
    BSTree<int>* tree;
};
