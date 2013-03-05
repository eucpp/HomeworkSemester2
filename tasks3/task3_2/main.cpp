/**
  * @brief Task 3_2
  *        Program creates the matrix with size 5x5 and outputs it to the display/file
  *        bypassing by spiral starting in central element
  */

#include <iostream>
#include <string>
#include "displayOut.h"
#include "fileOut.h"
#include "spiralDetour.h"

using namespace std;

int main()
{
    const int n = 3;
    int** array = new int*[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            array[i][j] = i * n + j + 1;
        }
    }

    string spiral = SpiralDetour::detourMatrix(array, n);

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
        output->output(spiral);
        cout << endl;
    }
    else if (dest == 1)
    {
        output = new FileOut();
        output->output(spiral);
        cout << "Check out.txt" << endl;
    }
    delete output;

    for (int i = 0; i < n; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

