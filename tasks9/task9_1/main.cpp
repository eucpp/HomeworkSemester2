#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "iteratorTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    IteratorTest test;
    QTest::qExec(&test);

    return a.exec();
}
