#pragma once

#include "sortable.h"

/**
  * @brief Sorter is an abstract class that is used to sort arrays of objects
  *        which override the compare & assigment operators
  */
template <typename Type> class Sorter
{
public:
    /**
      *
      * @param[in, out] array The pointer to an array of pointers to objects being sorted
      * @param[in] arraySize Size of the sorted part of array
      */
    virtual void sort(Type* array, const int arraySize) = 0;
    virtual ~Sorter() {}
};


