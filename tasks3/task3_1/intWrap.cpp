#include "intWrap.h"

bool IntWrap::operator==(IntWrap& obj)
{
    return (integer == obj.integer);
}
bool IntWrap::operator!=(IntWrap& obj)
{
    return (integer != obj.integer);
}
bool IntWrap::operator<(IntWrap& obj)
{
    return (integer < obj.integer);
}
bool IntWrap::operator>(IntWrap& obj)
{
    return (integer > obj.integer);
}
bool IntWrap::operator<=(IntWrap& obj)
{
    return (integer <= obj.integer);
}
bool IntWrap::operator>=(IntWrap& obj)
{
    return (integer >= obj.integer);
}
IntWrap& IntWrap::operator=(IntWrap& obj)
{
    integer = obj.integer;
    return *this;
}
IntWrap& IntWrap::operator=(int i)
{
    integer = i;
    return *this;
}
int IntWrap::getInt() const
{
    return integer;
}
