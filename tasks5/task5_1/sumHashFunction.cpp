#include "sumHashFunction.h"

SumHashFunction::SumHashFunction() {}

int getCode(const QChar ch)
{
    if (ch.isLetter())
        return ch.toAscii() - 'a' + 1;
    else if (ch.isNumber())
        return ch.toAscii() - '0' + 27;
    else
        return 0;
}

unsigned int SumHashFunction::hash(const QString& key) const
{
        unsigned int hashCode = 0;
        QString::const_iterator itr;
        int digit = 0;
        for (itr = key.begin(); itr != key.end(); itr++)
        {
            QChar ch = (*itr).toLower();
            int code = ::getCode(ch);
            hashCode += code * pow(base, digit);
            digit++;
        }
        return hashCode;
}
