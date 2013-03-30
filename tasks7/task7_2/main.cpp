#include <QtCore/QCoreApplication>
#include <QtTest/QTest>
#include "uniqueList.h"
#include "uniqueListTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject* listTest = new UniqueListTest();
    QTest::qExec(listTest);
    delete listTest;
    
    return a.exec();
}
