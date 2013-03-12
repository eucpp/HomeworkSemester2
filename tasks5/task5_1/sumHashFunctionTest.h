#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "sumHashFunction.h"

class SumHashFunctionTest : public QObject, private SumHashFunction
{
    Q_OBJECT
public:
    explicit SumHashFunctionTest(QObject *parent = 0) {}
private slots:
    void hashTest()
    {
        unsigned int expected = 1 + 27 * base + 4 * base * base;
        QCOMPARE(hash(QString("a0d")), expected);
    }
};
