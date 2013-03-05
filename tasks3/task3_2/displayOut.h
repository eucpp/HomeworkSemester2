#pragma once

#include <iostream>
#include "abstractOut.h"

/**
  * @brief Class outputs the strings to the dispay
  * @see AbstactOut
  */
class DisplayOut : public AbstractOut
{
public:
    DisplayOut() {}
    void print(string::iterator ch);
};

