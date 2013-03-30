#pragma once

#include <exception>

using std::exception;

class AddExistedExc : public exception
{
public:
    virtual const char* what() const throw();
};


