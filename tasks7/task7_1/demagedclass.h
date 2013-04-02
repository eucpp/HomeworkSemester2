#pragma once

#include <iostream>
#include "killedclass.h"

using namespace std;

class ConstructException
{};

class DemagedClass
{
public:
    DemagedClass() throw(ConstructException);
    ~DemagedClass();
private:
    KilledClass killed;
};


