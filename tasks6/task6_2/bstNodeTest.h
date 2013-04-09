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
    void operatorEqualTest()
    {
        BSTNode<int>* node2 = new BSTNode<int>(2, NULL, NULL);
        node->setValue(2);
        QVERIFY(*node == *node2);
        delete node2;
    }
    void setHeightTest()
    {
        node->setHeight(2);
    }
    void getHeightTest1()
    {
        node->setHeight(3);
        QCOMPARE(node->getHeight(), static_cast<unsigned int>(3));
    }
    void getHeightTest2()
    {
        BSTNode<int>* newNode = new BSTNode<int>(5, NULL, NULL);
        node->setLeftChild(newNode);
        QCOMPARE(node->getHeight(), static_cast<unsigned int>(1));
    }
    void getHeightTest3()
    {
        BSTNode<int>* newNode = new BSTNode<int>(5, NULL, NULL);
        newNode->setHeight(5);
        node->setLeftChild(newNode);
        QCOMPARE(node->getHeight(), static_cast<unsigned int>(6));
    }
    void setNumTest()
    {
        node->setNum(5);
    }
    void getNumTest1()
    {
        node->setNum(5);
        QCOMPARE(node->getNum(), static_cast<unsigned int>(5));
    }
    void incrementTest()
    {
        ++(*node);
        QCOMPARE(node->getNum(), static_cast<unsigned int>(2));
    }
    void decrementTest()
    {
        --(*node);
        QCOMPARE(node->getNum(), static_cast<unsigned int>(0));
    }
    void getBalanceFactorTest1()
    {
        BSTNode<int>* newLeftNode = new BSTNode<int>(5, NULL, NULL);
        newLeftNode->setHeight(5);
        BSTNode<int>* newRightNode = new BSTNode<int>(7, NULL, NULL);
        newRightNode->setHeight(7);
        node->setLeftChild(newLeftNode);
        node->setRightChild(newRightNode);
        QCOMPARE(node->getBalanceFactor(), -2);
    }
    void getBalanceFactorTest2()
    {
        BSTNode<int>* newLeftNode = new BSTNode<int>(5, NULL, NULL);
        newLeftNode->setHeight(5);
        node->setLeftChild(newLeftNode);
        QCOMPARE(node->getBalanceFactor(), 5);
    }

private:
    BSTNode<int>* node;
};
