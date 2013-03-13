#include "xorHashFunction.h"

unsigned int XORHashFunction::hash(const QString& key) const
{
    unsigned int hash = 0;
    QString::const_iterator itr;
    for (itr = key.begin(); itr != key.end(); itr++)
    {
        QChar ch = (*itr);
        hash += ch.toAscii() ^ bitMask;
    }
    return hash * key.length();
}
