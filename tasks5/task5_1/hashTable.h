#pragma once

#include <QString>
#include "../../tasks2/task2_1/abstractList.h"
#include "../../tasks2/task2_1/singleLinkedList.h"
#include "../../tasks2/task2_1/accessToEmptyExc.h".h"
#include "hashFunction.h"
#include "sumHashFunction.h"


template <typename Type> class HashTable
{
public:
    HashTable(unsigned int tableSize, HashFunction* hashFunction): size(tableSize), hashFunc(hashFunction),
        amount(0), collision(0)
    {
        for (unsigned int i = 0; i < size; ++i)
            table[i] = new SingleLinkedList<Type>;
    }
    /**
      * @brief Adding new element to the hash table
      * @param[in] key The key string of added element
      * @param[in] val Element for adding
      */
    void addElement(const QString key, const Type val)
    {
        unsigned int hash = hashFunc->hash(key) % size;
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
    }
    /**
      * @brief Deleting element with passed key
      * @param[in] key Key of the deleted element
      */
    void deleteElement(const QString key)
    {
        // find cell which contained key
        AbstractList<Type>* cell = findCell(key);
        cell->removeElement();
        // move internal pointer of list back to the head
        cell->head();
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
protected:
    /**
      * @brief Method try to find element with passed key in hash table
      *        If the hash table contains this element method will return link to the list
      *        and move the internal pointer of current element of list to the found element
      *        In another case method will return NULL
      * @param[in] key Key of the searched element
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
private:
    HashFunction* hashFunc;
    AbstractList<Type>** table;
    unsigned int size;
    unsigned int amount;
    unsigned int collision;
};
