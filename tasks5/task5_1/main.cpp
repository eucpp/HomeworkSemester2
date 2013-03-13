#include <QtGui/QApplication>
#include <QtTest/QTest>
#include "hashTable.h"
#include "hashTableManager.h"
#include "hashFunction.h"
#include "sumHashFunctionTest.h"
#include "hashTableTest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HashTableManager w;
    w.show();
    QObject* testHashFunc = new SumHashFunctionTest();
    QTest::qExec(testHashFunc);
    QObject* testHashTable = new HashTableTest();
    QTest::qExec(testHashTable);

    delete testHashFunc;
    delete testHashTable;

    return a.exec();
}
