#pragma once

#include <exception>

using std::exception;

/**
  * @brief Exception that thrown when try to access to the non existent element of matrix or column happens
  */
class OutOfMatrixSizeExc : public exception
{
public:
    virtual const char* what() const throw();
};
