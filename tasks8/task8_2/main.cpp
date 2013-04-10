#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "vectorTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    VectorTest* test = new VectorTest;
    QTest::qExec(test);
    delete test;

    return a.exec();
}
