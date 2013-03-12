#include <QtGui/QApplication>
#include <QtTest/QTest>
#include "hashTableManager.h"
#include "hashFunction.h"
#include "sumHashFunctionTest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HashTableManager w;
    w.show();
    QObject* test1= new SumHashFunctionTest();
    QTest::qExec(test1);
    delete test1;

    return a.exec();
}
