#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include <robotpanel.h>

class RobotPanelTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        panel = new RobotPanel(new Robot, true);
    }
    void cleanup()
    {
        delete panel;
    }

    void motorOnTest()
    {
        QByteArray actual = panel->motorOn(0, 100);
        QString expected('B');
        expected.append(RobotPanel::motorOnCode);
        expected.append(0);
        expected.append(static_cast<char>(100));
        QVERIFY(compareBytes(actual, expected));
    }
    void motorOffTest()
    {
        QByteArray actual = panel->motorOff(0);
        QString expected('B');
        expected.append(RobotPanel::motorOffCode);
        expected.append(0);
        QVERIFY(compareBytes(actual, expected));
    }
    void distanceSensorTest()
    {
        QByteArray actual = panel->distanceSensor(0);
        QString expected('B');
        expected.append(RobotPanel::distanceCode);
        expected.append(0);
        QVERIFY(compareBytes(actual, expected));
    }
    void touchSensorTest()
    {
        QByteArray actual = panel->touchSensor(0);
        QString expected('B');
        expected.append(RobotPanel::touchSensorCode);
        expected.append(0);
        QVERIFY(compareBytes(actual, expected));
    }

private:
    bool compareBytes(QByteArray actual, QString expected)
    {
        return (actual == expected);
    }

    RobotPanel* panel;
};
