#pragma once

#include "bsTree.h"

/**
  * @brief Class realises methods for work with sets.
  *        Operations of union and intersection two sets also implemented as a static functions.
  *        The set is implemented using a binary search tree
  */
template <typename Type> class Set
{
public:
    Set()
    {
        tree = new BSTree<Type>;
    }
    ~Set()
    {
        delete tree;
    }
    void addElement(Type elem)
    {
        tree->addValue(elem);
    }
    void deleteElement(Type elem)
    {
        tree->removeValue(elem);
    }
    bool has(Type elem)
    {
        return tree->valueExist(elem);
    }
    QStack<Type> getSetElements()
    {
        return tree->detourTree();
    }
    static Set<Type>* unionSets(Set<Type>* set1, Set<Type>* set2);
    /**{

            QStack<Type> set1Elements = set1->tree->detourTree();
            QStack<Type> set2Elements = set2->tree->detourTree();
            Set<Type>* resultSet = new Set<Type>;
            while (!set1Elements.isEmpty())
            {
                resultSet->addElement(set1Elements.pop());
            }
            while (!set2Elements.isEmpty())
            {
                resultSet->addElement(set2Elements.pop());
            }
            return resultSet;

    }*/

    static Set<Type>* intersectionSets(Set<Type>* set1, Set<Type>* set2);

private:
    BSTree<Type>* tree;
};

template <typename Type>
Set<Type>* Set<Type>::unionSets(Set<Type>* set1, Set<Type>* set2)
{
    QStack<Type> set1Elements = set1->tree->detourTree();
    QStack<Type> set2Elements = set2->tree->detourTree();
    Set<Type>* resultSet = new Set<Type>;
    while (!set1Elements.isEmpty())
    {
        resultSet->addElement(set1Elements.pop());
    }
    while (!set2Elements.isEmpty())
    {
        resultSet->addElement(set2Elements.pop());
    }
    return resultSet;
}

template <typename Type>
Set<Type>* Set<Type>::intersectionSets(Set<Type>* set1, Set<Type>* set2)
{
    QStack<Type> set1Elements = set1->tree->detourTree();
    Set<Type>* resultSet = new Set<Type>;
    while (!set1Elements.isEmpty())
    {
        Type elem = set1Elements.pop();
        if (set2->has(elem))
            resultSet->addElement(elem);
    }
    return resultSet;
}

