/**
  * @brief Task 3_3
  *        Program sorts the columns of matrix by their first elements
  */

#include <iostream>
#include <exception>
#include <stdlib.h>
#include "matrix.h"

using namespace std;

/*
void columnTest()
{
    cout << "Column class test" << endl;
    Column<int, 2> col1;
    col1[0] = 2;
    col1[1] = 3;
    Column<int, 2> col2;
    cout << "col1 = (" << col1[0] << ", " << col1[1] << ")" << endl;
    cout << "col2 = (" << col2[0] << ", " << col2[1] << ")" << endl;
    if (col1 == col2)
        cout << "col1 == col2" << endl;
    if (col1 != col2)
        cout << "col1 != col2" << endl;
    if (col1 > col2)
        cout << "col1 > col2" << endl;
    Column<int, 0> col3;
    Column<int, 0> col4;
    if (col3 == col4)
        cout << "col3 == col4" << endl;
    if (col3 != col4)
        cout << "col3 != col4" << endl;
    if (col3 > col4)
        cout << "col3 > col4" << endl;
    try
    {
        int i = col3[4];
    }
    catch (std::exception* exc)
    {
        cout << exc->what();
    }
    cout << endl;
}
*/

int main()
{
    const int rows = 5;
    const int cols = 5;
    Matrix<int, rows, cols> matrix;

    cout << "Before sorting" << endl;
    srand(time(0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[j][i] = rand() % 10;
            cout << matrix[j][i] << " | ";
        }
        cout << endl;
    }
    cout << endl;
    matrix.sortColumns();
    cout << "After sorting" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[j][i] << " | ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

