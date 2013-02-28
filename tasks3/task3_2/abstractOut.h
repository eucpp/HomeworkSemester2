#pragma once
#include <string>

using namespace std;
/**
  * @brief Abstract class used for output the strings to something
  *        All heirs of this class must just override print method
  */
class AbstractOut
{
public:
    AbstractOut() {}
    virtual ~AbstractOut() {}
    /**
      * @brief Method calls the Print method for each char in the string
      * @param[in] input String for output
      */
    void output(string input);
private:
    /**
      * @brief This method print chars to something
      *        and it must be overridden in the heirs of AbstactOut
      *
      */
    virtual void print(string::iterator ch)= 0;
};
