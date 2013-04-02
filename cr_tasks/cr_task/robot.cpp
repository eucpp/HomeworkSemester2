#include "robot.h"

Robot::Robot()
{}

QByteArray Robot::command(Command* cmd)
{
    std::cout << cmd->getCommand().data() << std::endl;
    emit response(cmd->getCommand());
    return cmd->getCommand();
}
