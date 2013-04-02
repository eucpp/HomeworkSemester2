#include "command.h"

Command::Command()
{}

void Command::setCommandCode(char code)
{
    cmd[1] = code;
}
void Command::setPort(char port)
{
    cmd[2] = port;
}
void Command::setParam(char param)
{
    cmd[3] = param;
}
QByteArray Command::getCommand()
{
    return cmd;
}
