#pragma once

#include <stdlib.h>
#include "sorter.h"

/**
  * @see Sorter
  */
template <typename Type> class QuickSortSorter : public Sorter<Type>
{
public:
    QuickSortSorter<Type>() {}
    ~QuickSortSorter() {}
    /**
      * @brief Realization of quick-sort algorithm
      * @see Sorter::sort
      */
    void sort(Type* array, const int arraySize)
    {
        quickSort(array, 0, arraySize - 1);
    }
private:
    void swap(Type& first, Type& second)
    {
        Type tmp = first;
        first = second;
        second = tmp;
    }
    /**
      * @brief Method sort the part of array
      * @param[in, out] array
      * @param[in] start Index beginning from which the sorting will start
      * @param[out] end Index in which the sorting is over
      */
    void quickSort(Type *array, const int start, const int end)
    {
        int i = start;
        int j = end;
        int offset = rand() % (end - start + 1);
        int x = start + offset;
        while (i < j)
        {
            while ((i < x) && (array[i] <= array[x]))
                ++i;
            while ((j > x) && (array[j] > array[x]))
                --j;
            if (i != j)
            {
                swap(array[i], array[j]);
                if (i == x)
                {
                    x = j;
                }
                else if (j == x)
                {
                    x = i;
                }
            }
        }
        if (x != start)
        {
            quickSort(array, start, x - 1);
        }
        if (x != end)
        {
            quickSort(array, x + 1, end);
        }
    }
};
