#pragma once

#include "iterator.h"
#include "../../tasks8/task8_1/avlTree.h"

template <typename Type> class AVLTreeIterator : public Iterator<Type>
{
public:
    /**
      * Create new iterator of AVL tree.
      *
      * @param tree Pointer to the tree.
      * @param elems Iterated elements.
      */
    AVLTreeIterator(AVLTree<Type>* tree, const QStack<Type>& elems):
        container(tree),
        elements(elems)
    {}

    Type next()
    {
        return elements.pop();
    }
    bool hasNext()
    {
        return !elements.isEmpty();
    }
    void add(Type elem)
    {
        container->addValue(elem);
    }
    void remove()
    {
        Type removed = elements.pop();
        container->removeValue(removed);
    }
private:
    QStack<Type> elements;
    AVLTree<Type>* container;
};


