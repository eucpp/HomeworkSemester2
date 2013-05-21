#include "doubleComparator.h"

int DoubleComparator::compare(double obj1, double obj2)
{
    if ((obj1 > obj2) && (obj1 - obj2 > eps))
        return 1;
    if (qAbs(obj1 - obj2) < eps)
        return 0;
    if ((obj1 < obj2) && (obj2 - obj1 > eps))
        return -1;
}
