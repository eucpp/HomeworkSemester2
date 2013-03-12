#include "accessToEmptyExc.h"


const char* AccessToEmptyExc::what() const throw()
{
    return "Try to get element which doesn't exist";
}

