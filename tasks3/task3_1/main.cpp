/**
  * @brief Task 3_1
  *        Program realize two classes of the sorter that can sorting arrays of any comparable objects
  */

#include <iostream>
#include <stdlib.h>
#include "quickSortSorter.h"
#include "intWrap.h"

using namespace std;

/**
  * @brief Main include a test of the sorters
  *        Array of IntWrap objects is created and filled by random integer numbers
  *        Then the array is sorted and displayed
  */
int main()
{
    const int arraySize = 15;
    IntWrap* array = new IntWrap[arraySize];
    cout << "Before sorting" << endl;
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 10;
        cout << array[i].getInt() << " | ";
    }
    cout << endl;

    Sorter<IntWrap>* sorter = new QuickSortSorter<IntWrap>;
    sorter->sort(array, arraySize);

    cout << "After sorting" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i].getInt() << " | ";
    }
    cout << endl;
    delete [] array;

    return 0;
}

