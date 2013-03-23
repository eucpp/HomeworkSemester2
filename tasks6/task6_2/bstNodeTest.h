#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "bstNode.h"

class BSTNodeTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        node = new BSTNode<int>(0, NULL, NULL);
    }
    void cleanup()
    {
        delete node;
    }
    void setLeftChildTest()
    {
        node->setLeftChild(new BSTNode<int>(0, NULL, NULL));
    }
    void setRightChildTest()
    {
        node->setRightChild(new BSTNode<int>(0, NULL, NULL));
    }
    void getLeftChildTest()
    {
        BSTNode<int>* lCh = new BSTNode<int>(1, NULL, NULL);
        node->setLeftChild(lCh);
        QCOMPARE(node->getLeftChild(), lCh);
    }
    void getRightChildTest()
    {
        BSTNode<int>* rCh = new BSTNode<int>(1, NULL, NULL);
        node->setRightChild(rCh);
        QCOMPARE(node->getRightChild(), rCh);
    }
    void setValueTest()
    {
        node->setValue(5);
    }
    void getValueTest()
    {
        node->setValue(2);
        QCOMPARE(node->getValue(), 2);
    }
    void isLeafTest1()
    {
        QVERIFY(node->isLeaf());
    }
    void isLeafTest2()
    {
        BSTNode<int>* rCh = new BSTNode<int>(1, NULL, NULL);
        node->setRightChild(rCh);
        QVERIFY(!node->isLeaf());
    }
    /*
    void operatorEqualTest()
    {
        BSTNode<int>* node2 = new BSTNode<int>(2, NULL, NULL);
        node->setValue(2);
        QVERIFY(*node == *node2);
        delete node2;
    }
    */
private:
    BSTNode<int>* node;
};
