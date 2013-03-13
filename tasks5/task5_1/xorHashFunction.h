#pragma once

#include "hashFunction.h"

class XORHashFunction : public HashFunction
{
public:
    /**
      * @brief This hash function uses XOR for all chars in the string
      *        Then adds the results and multiplies it on the string length
      * @see HashFunction::hash
      */
    unsigned int hash(const QString& key) const;
private:
    static const char bitMask = 0x9A;
};

