#include "demagedclass.h"


DemagedClass::DemagedClass() throw(ConstructException)
{
    cout << "DemagedClass constructor called" << endl;
    throw ConstructException();
}
DemagedClass::~DemagedClass()
{
    cout << "DemagedClass destructor called" << endl;
}
