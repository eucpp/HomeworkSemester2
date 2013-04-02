#pragma once

#include "command.h"

class BluetoothCommand : public Command
{
public:
    BluetoothCommand()
    {
        cmd[0] = 'B';
    }
};
