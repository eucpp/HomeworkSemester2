#pragma once

#include "outOfMatrixSizeExc.h"

/**
  * @brief Column is a class of matrix column for task 3_3
  *        This class override relational operators such that column with bigger first element
  *        considered as the bigger object than another one
  */
template <typename Type, unsigned int Size> class Column
{
public:
    Column()
    {
        col = new Type[Size];
        for (int i = 0; i < Size; i++)
            col[i] = 0;
    }
    Column(Column<Type, Size>& obj)
    {
        col = new Type[Size];
        for (int i = 0; i < Size; i++)
            col[i] = obj.col[i];
    }
    ~Column()
    {
        delete[] col;
    }
    bool operator==(Column<Type, Size>& obj)
    {
        return (Size == 0 || col[0] == obj.col[0]);
    }
    bool operator!=(Column<Type, Size>& obj)
    {
        return (Size != 0 && col[0] != obj.col[0]);
    }
    bool operator<(Column<Type, Size>& obj)
    {
        return (Size != 0 && col[0] < obj.col[0]);
    }
    bool operator>(Column<Type, Size>& obj)
    {
        return (Size != 0 && col[0] > obj.col[0]);
    }
    bool operator<=(Column<Type, Size>& obj)
    {
        return (Size != 0 && col[0] <= obj.col[0]);
    }
    bool operator>=(Column<Type, Size>& obj)
    {
        return (Size != 0 && col[0] >= obj.col[0]);
    }
    Type& operator[](const int i) throw(OutOfMatrixSizeExc*)
    {
        if (i >= Size || i < 0)
            throw new OutOfMatrixSizeExc;
        return col[i];
    }
    Column<Type, Size>& operator=(Column<Type, Size>& obj)
    {
        for (int i = 0; i < Size; i++)
            col[i] = obj.col[i];
        return *this;
    }
private:
    Type* col;
};

