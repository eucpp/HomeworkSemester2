#pragma once

#include <iostream>
#include <QObject>
#include <QByteArray>
#include "command.h"

/**
  *
  */
class Robot : public QObject
{
    Q_OBJECT
public:
    Robot();
public slots:
    QByteArray command(Command *cmd);
signals:
    void response(QByteArray);
};

