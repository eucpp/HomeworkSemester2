#ifndef DOUBLECOMPARATOR_H
#define DOUBLECOMPARATOR_H

#include <QObject>
#include "comparator.h"

class DoubleComparator : public Comparator<double>
{
public:
    DoubleComparator() {}
    ~DoubleComparator() {}
    int compare(double obj1, double obj2);
private:
    static const double eps = 0.001;
};

#endif // DOUBLECOMPARATOR_H
