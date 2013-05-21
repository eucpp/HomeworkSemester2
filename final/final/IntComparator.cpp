#include "IntComparator.h"

int IntComparator::compare(int obj1, int obj2)
{
    if (obj1 > obj2)
        return 1;
    if (obj1 == obj2)
        return 0;
    if (obj1 < obj2)
        return -1;
}
