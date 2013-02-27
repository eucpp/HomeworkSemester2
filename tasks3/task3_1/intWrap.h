#pragma once

#include "sortable.h"

/**
  * @brief Class-wrap for standart type int used to test Sorter class
  */
class IntWrap
{
public:
    IntWrap(): integer(0) {}
    IntWrap(const int i): integer(i) {}
    int getInt() const;
    bool operator==(IntWrap& obj);
    bool operator!=(IntWrap& obj);
    bool operator<(IntWrap& obj);
    bool operator>(IntWrap& obj);
    bool operator<=(IntWrap& obj);
    bool operator>=(IntWrap& obj);
    IntWrap& operator=(IntWrap& obj);
    IntWrap& operator=(int i);
private:
    int integer;
};
