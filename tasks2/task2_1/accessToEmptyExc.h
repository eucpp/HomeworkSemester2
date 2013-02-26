#pragma once

#include <exception>

using std::exception;

class AccessToEmptyExc : public exception
{
public:
    virtual const char* what() const throw();
};
