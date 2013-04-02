#pragma once

#include <QObject>
#include "robot.h"
#include "command.h"
#include "bluetoothcommand.h"
#include "usbcommand.h"

/**
  * Class for manage robot
  */
class RobotPanel : public QObject
{
    Q_OBJECT
public:
    /**
      *
      * @param robotObj robot object for managment
      * @param connection type of connection with robot
      *                   true - bluetooth
      *                   false - usb
      */
    RobotPanel(Robot* robotObj, bool connection);
    enum Commands
    {
        motorOnCode,
        motorOffCode,
        touchSensorCode,
        distanceCode
    };
public slots:
    QByteArray motorOn(char port, char power);
    QByteArray motorOff(char port);
    QByteArray touchSensor(char port);
    QByteArray distanceSensor(char port);
private:
    void sendCommand(int commandCode, int port);
    Command* getCommandObj();
    /**
      * Connection with robot type
      * true - bluetooth
      * false - usb
      */
    bool connectionType;
    Robot* robot;
};


