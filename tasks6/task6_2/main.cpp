#include <QtGui/QApplication>
#include <QObject>
#include <QtTest/QtTest>
#include "mainwindow.h"
#include "bstNode.h"
#include "bstNodeTest.h"
#include "bsTree.h"
#include "bsTreeTest.h"

int main(int argc, char *argv[])
{
    BSTNodeTest* nodeTest = new BSTNodeTest;
    QTest::qExec(nodeTest);
    delete nodeTest;
    BSTreeTest* treeTest = new BSTreeTest;
    QTest::qExec(treeTest);
    delete treeTest;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
