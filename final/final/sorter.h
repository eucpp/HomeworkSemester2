#ifndef SORTER_H
#define SORTER_H

#include "comparator.h"

template <typename Type> class Sorter
{
public:
    Sorter(Comparator<Type>* pComparator):
        comparator(pComparator)
    {}
    ~Sorter()
    {
        delete comparator;
    }
    void setComparator(Comparator<Type>* pComparator)
    {
        delete comparator;
        comparator = pComparator;
    }
    /**
      * Method sorts the array using bubble-sort algorithm.
      */
    void sort(Type* array, int size);
private:
    Comparator<Type>* comparator;
};

template <typename Type>
void Sorter<Type>::sort(Type* array, int size)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (comparator->compare(array[i], array[i + 1]) == 1)
            {
                sorted = false;
                Type tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
            }
        }
    }
}

#endif // SORTER_H
