#include <QtCore/QCoreApplication>

#include <QObject>
#include <QtTest/QtTest>
#include "RobotPanelTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    RobotPanelTest* test = new RobotPanelTest;
    QTest::qExec(test);
    delete test;

    return a.exec();
}
