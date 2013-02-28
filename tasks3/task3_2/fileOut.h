#pragma once

#include <fstream>
#include "abstractOut.h"

using namespace std;

/**
  * @brief Class outputs the strings to the file out.txt in current directory
  * @see AbstactOut
  */
class FileOut : public AbstractOut
{
public:
    FileOut();
    ~FileOut();
private:
    /**
      * @property Output file stream
      */
    ofstream file;
    void print(string::iterator ch);
};
