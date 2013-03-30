#include "addExistedExc.h"

const char* AddExistedExc::what() const throw()
{
    return "Try to add element, which existed in list already";
}
