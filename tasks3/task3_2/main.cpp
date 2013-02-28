/**
  * @brief Task 3_2
  *        Program creates the matrix with size 5x5 and outputs it to the display/file
  *        bypassing by spiral starting in central element
  */

#include <iostream>
#include <sstream>
#include <string>
#include "displayOut.h"
#include "fileOut.h"

using namespace std;

int main()
{
    const int n = 3;
    int array[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = i * n + j + 1;
        }
    }

    string spiral = "";
    stringstream spiralStream(spiral, ios_base::out);
    int row = n / 2;
    int col = n / 2;
    bool direction = true; // true - rigth & up; false - left & down
    spiralStream << array[row][col] << " | ";
    for (int i = 1; i < n; i++)
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
            spiralStream << array[row][col] << " | ";
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
            spiralStream << array[row][col] << " | ";
        }
        direction = !direction;
    }
    for (int i = 1; i < n; ++i)
    {
        col++;
        spiralStream << array[row][col] << " | ";
    }

    cout << "Enter the destination for output" << endl;
    cout << "0 - Display" << endl;
    cout << "1 - File" << endl;
    int dest = 0;
    cin >> dest;
    cout << endl;
    AbstractOut* output;
    if (dest == 0)
    {
        output = new DisplayOut();
        cout << "Spiral: ";
        output->output(spiralStream.str());
        cout << endl;
    }
    else if (dest == 1)
    {
        output = new FileOut();
        output->output(spiralStream.str());
        cout << "Check out.txt" << endl;
    }
    delete output;

    return 0;
}

