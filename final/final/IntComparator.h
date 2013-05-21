#ifndef INTCOMPARATOR_H
#define INTCOMPARATOR_H

#include "comparator.h"

class IntComparator : public Comparator<int>
{
public:
    IntComparator() {}
    ~IntComparator() {}
    int compare(int obj1, int obj2);
};

#endif // INTCOMPARATOR_H
