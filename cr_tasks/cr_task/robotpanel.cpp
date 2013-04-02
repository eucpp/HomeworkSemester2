#include "robotpanel.h"

RobotPanel::RobotPanel(Robot *robotObj, bool connection):
    robot(robotObj),
    connectionType(connection)
{}

QByteArray RobotPanel::motorOn(char port, char power)
{
    Command* cmd = getCommandObj();
    cmd->setCommandCode(motorOnCode);
    cmd->setPort(port);
    cmd->setParam(power);
    return robot->command(cmd);
}

QByteArray RobotPanel::motorOff(char port)
{
    Command* cmd = getCommandObj();
    cmd->setCommandCode(motorOffCode);
    cmd->setPort(port);
    return robot->command(cmd);
}

QByteArray RobotPanel::touchSensor(char port)
{
    Command* cmd = getCommandObj();
    cmd->setCommandCode(touchSensorCode);
    cmd->setPort(port);
    return robot->command(cmd);
}

QByteArray RobotPanel::distanceSensor(char port)
{
    Command* cmd = getCommandObj();
    cmd->setCommandCode(distanceCode);
    cmd->setPort(port);
    return robot->command(cmd);
}
Command* RobotPanel::getCommandObj()
{
    if (connectionType)
        return new BluetoothCommand;
    else
        return new USBCommand;
}


