#pragma once

#include <QtGlobal>
#include "avlTree.h"

/**
  * Structure for storage things.
  * There are two fields: thing & num of this thing
  */
template <typename Type> struct Things
{
    Type thing;
    unsigned int num;
};

/**
  * Bag (multiset) - class for the work with sets of objects (things).
  * It includes methods to put/pulls things to/from bag and search them.
  */
template <typename Type> class Bag
{
public:
    Bag()
    {
        tree = new AVLTree<Type>;
    }
    ~Bag()
    {
        delete tree;
    }

    void put(Type thing, unsigned int num)
    {
        tree->addValue(thing, num);
    }
    Things<Type> pull(Type thing, unsigned int num)
    {
        Things<Type> result;
        result.thing = thing;
        result.num = qMin(tree->elemNum(thing), num);
        if (result.num != 0)
            tree->removeValue(thing, num);
        return result;
    }
    bool search(Type thing)
    {
        return tree->valueExist(thing);
    }
    /**
      * Count all things in the bag and return result
      */
    unsigned int count()
    {
        return tree->countNodes();
    }

private:
    AVLTree<Type>* tree;
};
