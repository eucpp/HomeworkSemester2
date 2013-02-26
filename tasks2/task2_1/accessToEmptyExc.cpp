#include "accessToEmptyExc.h"


const char* AccessToEmptyExc::what() const throw()
{
    return "Try to get value from empty container";
}

