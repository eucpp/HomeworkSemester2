#pragma once

#include <QString>
#include <math.h>
#include "hashFunction.h"

class SumHashFunction : public HashFunction
{
public:
    SumHashFunction();
    /**
     * @brief This method considers key string as a polynom of x
     *        where coefficients is a codes of chars
     *        Hash is a value of polynom where x = base
     * @see HashFunction::hash()
     */
    unsigned int hash(const QString& key) const;
protected:
    /**
      * @brief This const used for substitution instead x in hash polynom
      *        Base = 37 because of that is the number of chars used in the key string
      *        Codes 1-26 - latin letters
      *        Codes 27-36 - numbers
      *        Code 0 - other chars
      */
    static const int base = 37;
};

