#include "fileOut.h"

FileOut::FileOut()
{
    file.open("out.txt");
}
FileOut::~FileOut()
{
    file.close();
}

void FileOut::print(string::iterator ch)
{
    file << *ch;
}
