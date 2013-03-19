#include <QtGui/QApplication>
#include <QtTest/QtTest>
#include "mainwindow.h"
#include "operandNodeTest.h"
#include "operatorNodeTest.h"
#include "parseTreeTest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    OperandNodeTest* oprndTest = new OperandNodeTest;
    QTest::qExec(oprndTest);
    delete oprndTest;
    OperatorNodeTest* oprtTest = new OperatorNodeTest;
    QTest::qExec(oprtTest);
    delete oprtTest;
    ParseTreeTest* treeTest = new ParseTreeTest;
    QTest::qExec(treeTest);
    delete treeTest;
    
    return a.exec();
}
