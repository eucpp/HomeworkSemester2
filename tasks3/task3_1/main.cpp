#include <iostream>
#include <stdlib.h>
#include "quickSortSorter.h"
#include "intWrap.h"

using namespace std;

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

