#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "operandNode.h"

class OperandNodeTest: public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        node = new OperandNode(1);
    }
    void cleanup()
    {
        delete node;
    }
    void setOperandTest()
    {
        node->setOperand(5);
    }
    void getOperandTest1()
    {
        QCOMPARE(node->getOperand(), 1);
    }
    void getOperandTest2()
    {
        node->setOperand(5);
        QCOMPARE(node->getOperand(), 5);
    }
    void calcTest()
    {
        QCOMPARE(node->calc(), 1.0);
    }
private:
    OperandNode* node;
};
