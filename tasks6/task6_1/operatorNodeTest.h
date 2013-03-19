#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "operatorNode.h"
#include "operandNode.h"

class OperatorNodeTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        node = new OperatorNode(NULL, NULL, '+');
    }
    void cleanup()
    {
        delete node;
    }
    void setLeftChildTest()
    {
        node->setLeftChild(new OperatorNode(NULL, NULL, '+'));
    }
    void setRightChildTest()
    {
        node->setRightChild(new OperatorNode(NULL, NULL, '+'));
    }
    void getLeftChildTest()
    {
        OperatorNode* lCh = new OperatorNode(NULL, NULL, '*');
        node->setLeftChild(lCh);
        QCOMPARE(node->getLeftChild(), lCh);
    }
    void getRightChildTest()
    {
        OperatorNode* rCh = new OperatorNode(NULL, NULL, '*');
        node->setRightChild(rCh);
        QCOMPARE(node->getRightChild(), rCh);
    }
    void setOperatorTest()
    {
        node->setOperator('/');
    }
    void getOperatorTest1()
    {
        QCOMPARE(node->getOperator(), QChar('+'));
    }
    void getOperatorTest2()
    {
        node->setOperator('/');
        QCOMPARE(node->getOperator(), QChar('/'));
    }
    void calcTest1()
    {
        node->setLeftChild(new OperandNode(10));
        node->setRightChild(new OperandNode(10));
        QCOMPARE(node->calc(), 20.0);
    }
    void calcTest2()
    {
        node->setLeftChild(new OperandNode(10));
        node->setRightChild(new OperandNode(0));
        node->setOperator('/');
        try
        {
            double result = node->calc();
            QFAIL("");
        }
        catch (IncorrectExprExc exc)
        {}
    }

private:
    OperatorNode* node;
};
