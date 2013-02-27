#pragma once

#include "column.h"
#include "../task3_1/sorter.h"
#include "../task3_1/quickSortSorter.h"

/**
  * @brief Matrix class for task 3_3
  */
template <typename Type, int rowSize, int colSize> class Matrix
{
public:
    Matrix()
    {
        cols = new Column<Type, rowSize>[colSize];
    }
    ~Matrix()
    {
        delete[] cols;
    }
    Column<Type, rowSize>& operator[](const int i) throw(OutOfMatrixSizeExc*)
    {
        if (i >= colSize || i < 0)
            throw new OutOfMatrixSizeExc;
        return cols[i];
    }
    /**
      * @brief Method sorts the columns of matrix by their first elements
      * @param[in] sorter An object of Sorter class which will use for sorting
      */
    void sortColumns()
    {
        typedef Column<Type, rowSize> columnType;
        Sorter<columnType>* sorter = new QuickSortSorter<columnType>;
        sorter->sort(cols, colSize);
        delete sorter;
    }

private:
    Column<Type, rowSize>* cols;
};

