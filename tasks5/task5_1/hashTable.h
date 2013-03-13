#pragma once

#include "limits.h"
#include <QString>
#include "../../tasks2/task2_1/abstractList.h"
#include "../../tasks2/task2_1/singleLinkedList.h"
#include "../../tasks2/task2_1/accessToEmptyExc.h"
#include "hashFunction.h"
#include "sumHashFunction.h"


template <typename Type> class HashTable
{
public:
    HashTable(unsigned int tableSize, HashFunction* hashFunction): size(tableSize), hashFunc(hashFunction),
        amount(0), collision(0)
    {
        initTable();
    }
    ~HashTable()
    {
        for (unsigned int i = 0; i < size; ++i)
        {
            if (table[i] == NULL)
                continue;
            delete table[i];
        }
        delete table;
        delete hashFunc;
    }
    /**
      * @brief Adding new element to the hash table
      * @param[in] key The key string of added element
      * @param[in] val Element for adding
      */
    void addElement(const QString key, const Type val)
    {
        unsigned int hash = hashFunc->hash(key) % size;
        if (table[hash] == NULL)
            table[hash] = new SingleLinkedList<int>;
        // add element if it doesn't contained in hash table yet
        if (!table[hash]->contains(key))
        {
            // increase counter of collisions if the cell doesn't empty
            if (!table[hash]->isEmpty())
                ++collision;
            table[hash]->addElement(val, key);
            // move internal pointer of list back to the head
            table[hash]->head();
            ++amount;
        }
        if (getLoadFactor() > 0.8 && size < UINT_MAX - size)
            restruct(size * 2);
    }
    /**
      * @brief Deleting element with passed key
      * @param[in] key Key of the deleted element
      */
    void deleteElement(const QString key)
    {
        // find cell which contained key
        AbstractList<Type>* cell = findCell(key);
        if (cell == NULL)
            return;
        cell->removeElement();
        // move internal pointer of list back to the head
        cell->head();
        --amount;
        if (!cell->isEmpty())
            --collision;
    }

    /**
      * @brief Method returns the element with the passed key or throws exception
      *        if the hash table doesn't contain this key
      * @param[in] key Key string associated with the element
      * @return Sought-for element
      */
    Type getElement(const QString key) throw(AccessToEmptyExc*)
    {
        AbstractList<Type>* cell = findCell(key);
        if (cell == NULL)
            throw new AccessToEmptyExc;
        Type val = cell->current();
        // move internal pointer of list back to the head
        cell->head();
        return val;
    }
    /**
      * @brief Set new hash function of table and restruct it
      * @param[in] hashFunction New hash function
      */
    void setHashFunction(HashFunction* hashFunction)
    {
        delete hashFunc;
        hashFunc = hashFunction;
        restruct;
    }

    double getLoadFactor()
    {
        return static_cast<double>(amount) / size;
    }
    unsigned int getMostLoadedCell()
    {
        unsigned int mostLoaded = 0;
        int maxLength = 0;
        for (unsigned int i = 0; i < size; ++i)
        {
            if (table[i] == NULL)
                continue;
            if (table[i]->count() > maxLength)
            {
                mostLoaded = i;
                maxLength = table[i]->count();
            }
            return mostLoaded;
        }
    }
    int getMostLoadedCellLength()
    {
        unsigned int mostLoaded = getMostLoadedCell();
        return table[mostLoaded]->count();
    }
    unsigned int getConflictCellsNum()
    {
        unsigned int conflictCells = 0;
        for (unsigned int i = 0; i < size; ++i)
        {
            if (table[i] == NULL)
                continue;
            if (table[i]->count() > 1)
                ++conflictCells;
        }
        return conflictCells;
    }
private:
    /**
      * @brief Method try to find element with passed key in hash table
      *        If the hash table contains this element method will return link to the list
      *        and move the internal pointer of current element of list to the found element
      *        In another case method will return NULL
      * @param[in] key Key of the searched element
      * @return AbstractList<Type>* Poitnter to the table cell contained sought-for element
      */
    AbstractList<Type>* findCell(const QString key)
    {
        unsigned int hash = hashFunc->hash(key) % size;
        table[hash]->head();
        if (table[hash]->isEmpty())
            return NULL;
        else
        {
            while (!table[hash]->isEOL())
            {
                if (key == table[hash]->currentKey())
                    return table[hash];
            }
            return NULL;
        }
    }
    void restruct(unsigned int newSize)
    {
        AbstractList<Type>** oldTable = table;
        unsigned int oldSize = size;
        size = newSize;
        initTable();
        amount = 0;
        collision = 0;
        for (unsigned int i = 0; i < oldSize; ++i)
        {
            if (oldTable[i] == NULL || oldTable[i]->isEmpty())
                continue;
            while (!oldTable[i]->isEOL())
            {
                addElement(oldTable[i]->currentKey(), oldTable[i]->current());
                oldTable[i]->next();
            }
        }
        for (unsigned int i = 0; i < oldSize; ++i)
        {
            if (oldTable[i] == NULL)
                continue;
            delete oldTable[i];
        }
        delete oldTable;
    }
    void initTable()
    {
        table = new AbstractList<Type>*[size];
        for (unsigned int i = 0; i < size; ++i)
            table[i] = NULL;
    }

    HashFunction* hashFunc;
    AbstractList<Type>** table;
    unsigned int size;
    unsigned int amount;
    unsigned int collision;
};
