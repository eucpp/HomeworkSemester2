#pragma once

#include <QObject>

class Command
{
public:
    Command();
    void setCommandCode(char code);
    void setPort(char port);
    void setParam(char param);
    QByteArray getCommand();
protected:
    QByteArray cmd;
};

