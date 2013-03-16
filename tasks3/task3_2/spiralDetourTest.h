#pragma once

#include <string>
#include <QObject>
#include <QtTest/QtTest>
#include "spiralDetour.h"

using namespace std;

class spiralDetourTest : public QObject
{
    Q_OBJECT
private:
    bool isSpiral(string str)
    {
        string pattern = "5 | 6 | 3 | 2 | 1 | 4 | 7 | 8 | 9 | ";
        if (str.length() != pattern.length())
            return false;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != pattern[i])
                return false;
        }
        return true;
    }
private slots:
    void detourMatrixTest()
    {
        const int n = 3;
        int** array = new int*[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                array[i][j] = i * n + j + 1;
            }
        }

        string spiral = SpiralDetour::detourMatrix(array, n);
        QVERIFY(isSpiral(spiral));
    }
};
