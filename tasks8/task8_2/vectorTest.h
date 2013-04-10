#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
private slots:
    void accessOperatorTest()
    {
        Vector<2> vect;
        vect[0] = 11;
        QVERIFY(vect[0] == 11);
    }
    void equalTest()
    {
        Vector<2> first;
        first[0] = 1;
        first[1] = 1;
        Vector<2> second;
        second[0] = 1;
        second[1] = 1;
        QVERIFY(first == second);
    }
    void copyConstructorTest()
    {
        Vector<2> origin;
        origin[0] = 1;
        origin[1] = 2;
        Vector<2> copy(origin);
        QVERIFY(copy == origin);
    }
    void assignmentOperatorTest()
    {
        Vector<2> origin;
        origin[0] = 1;
        origin[1] = 2;
        Vector<2> copy;
        copy = origin;
        QVERIFY(copy == origin);
    }
    void operatorPlusTest()
    {
        Vector<2> oprnd1;
        oprnd1[0] = 4;
        oprnd1[1] = 8;
        Vector<2> oprnd2;
        oprnd2[0] = 6;
        oprnd2[1] = -3;
        Vector<2> result = oprnd1 + oprnd2;
        int expected[2] = {10, 5};
        Vector<2> expResult(expected);
        QVERIFY(result == expResult);
    }
    void operatorMinusTest()
    {
        Vector<2> oprnd1;
        oprnd1[0] = 4;
        oprnd1[1] = 8;
        Vector<2> oprnd2;
        oprnd2[0] = 6;
        oprnd2[1] = -2;
        Vector<2> result = oprnd1 - oprnd2;
        int expected[2] = {-2, 10};
        Vector<2> expResult(expected);
        QVERIFY(result == expResult);
    }
    void scalarMultiplyTest()
    {
        Vector<2> oprnd1;
        oprnd1[0] = 1;
        oprnd1[1] = 5;
        Vector<2> oprnd2;
        oprnd2[0] = 5;
        oprnd2[1] = -1;
        int result = oprnd1 * oprnd2;
        QVERIFY(result == 0);
    }
    void isNullTest()
    {
        Vector<5> nullVect;
        QVERIFY(nullVect.isNull());
    }
};
