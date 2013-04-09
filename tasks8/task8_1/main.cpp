#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "../../tasks6/task6_2/bstNode.h"
#include "../../tasks6/task6_2/bstNodeTest.h"
#include "../../tasks6/task6_2/bsTree.h"
#include "../../tasks6/task6_2/bsTreeTest.h"
#include "avlTreeTest.h"
#include "bagTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BSTNodeTest* nodeTest = new BSTNodeTest;
    QTest::qExec(nodeTest);
    delete nodeTest;

    BSTreeTest* treeTest = new BSTreeTest;
    QTest::qExec(treeTest);
    delete treeTest;

    AVLTreeTest* avlTreeTest = new AVLTreeTest;
    QTest::qExec(avlTreeTest);
    delete avlTreeTest;

    BagTest* bagTest = new BagTest;
    QTest::qExec(bagTest);
    delete bagTest;
    
    return a.exec();
}
