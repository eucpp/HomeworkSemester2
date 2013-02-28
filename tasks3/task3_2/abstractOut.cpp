#include "abstractOut.h"

void AbstractOut::output(string input)
{
    for (string::iterator itr = input.begin(); itr != input.end(); ++itr)
        print(itr);
}

