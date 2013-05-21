#include <QtCore/QCoreApplication>

#include <QObject>
#include <QtTest>
#include "sorterTest.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    SorterTest* test = new SorterTest();
    QTest::qExec(test);
    delete test;

    return a.exec();
}
