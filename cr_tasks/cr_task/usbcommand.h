#pragma once

#include "command.h"

class USBCommand : public Command
{
public:
    USBCommand()
    {
        this->cmd[0] = 'U';
    }
};

