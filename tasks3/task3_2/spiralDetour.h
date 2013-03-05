#pragma once

#include <string>
#include <sstream>

using namespace std;

class SpiralDetour
{
public:
    SpiralDetour();
    static string detourMatrix(int **matrix, const int size);
};

