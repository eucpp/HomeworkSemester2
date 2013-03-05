#include "spiralDetour.h"

SpiralDetour::SpiralDetour()
{
}

 string SpiralDetour::detourMatrix(int **matrix, const int size)
{
    string spiral = "";
    stringstream spiralStream(spiral, ios_base::out);
    int row = size / 2;
    int col = size / 2;
    bool direction = true; // true - rigth & up; false - left & down
    spiralStream << matrix[row][col] << " | ";
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (direction)
            {
                col++;
            }
            else
            {
                col--;
            }
            spiralStream << matrix[row][col] << " | ";
        }
        for (int j = 1; j <= i; j++)
        {
            if (direction)
            {
                row--;
            }
            else
            {
                row++;
            }
            spiralStream << matrix[row][col] << " | ";
        }
        direction = !direction;
    }
    for (int i = 1; i < size; ++i)
    {
        col++;
        spiralStream << matrix[row][col] << " | ";
    }
    return spiralStream.str();
}
