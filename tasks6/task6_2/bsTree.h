#pragma once

#include <QStack>
#include "bstNode.h"

/**
  * @brief Class realises binary search tree algorithms
  */
template <typename Type> class BSTree
{
public:
    BSTree(): root(NULL) {}
    ~BSTree()
    {
        delete root;
    }
    void addValue(Type value)
    {
        BSTNode<Type>* newNode = new BSTNode<Type>(value, NULL, NULL);
        addNode(root, newNode);
    }
    void removeValue(Type removed)
    {
        BSTNode<Type>* removedNode = new BSTNode<Type>(removed, NULL, NULL);
        removeNode(root, removedNode);
    }
    bool valueExist(Type value)
    {
        return nodeExist(root, new BSTNode<Type>(value, NULL, NULL));
    }
    QStack<Type> detourTree()
    {
        QStack<Type> nodes;
        if (root == NULL)
            return nodes;
        root->detourNode(nodes);
        return nodes;
    }

private:
    void addNode(BSTNode<Type>*& dest, BSTNode<Type>* added);
    void removeNode(BSTNode<Type>*& node, BSTNode<Type>* removed);
    bool nodeExist(BSTNode<Type>* node, BSTNode<Type>* searched);
    BSTNode<Type>* getLeftmostChild(BSTNode<Type>* node);

    BSTNode<Type>* root;
};

template <typename Type>
void BSTree<Type>::addNode(BSTNode<Type>*& dest, BSTNode<Type>* added)
{
    if (dest == NULL)
        dest = added;
    if (*added < *dest)
        addNode(dest->getLeftChild(), added);
    else if (*added > *dest)
        addNode(dest->getRightChild(), added);
}

template <typename Type>
void BSTree<Type>::removeNode(BSTNode<Type>*& node, BSTNode<Type>* removed)
{
    if (node == NULL)
        return;
    if (*removed < *node)
    {
        removeNode(node->getLeftChild(), removed);
    }
    else if (*removed > *node)
    {
        removeNode(node->getRightChild(), removed);
    }
    else
    {
        if (node->isLeaf())
        {
            delete node;
            node = NULL;
        }
        else if (node->getLeftChild() != NULL && node->getRightChild() == NULL)
        {
            BSTNode<Type>* tmp = node;
            node = node->getLeftChild();
            tmp->setLeftChild(NULL);
            delete tmp;
        }
        else if (node->getLeftChild() == NULL && node->getRightChild() != NULL)
        {
            BSTNode<Type>* tmp = node;
            node = node->getRightChild();
            tmp->setRightChild(NULL);
            delete tmp;
        }
        else
        {
            BSTNode<Type>* leftmost = getLeftmostChild(node);
            node->setValue(leftmost->getValue());
            removeNode(node->getLeftChild(), leftmost);
        }
        delete removed;
    }
}

template <typename Type>
bool BSTree<Type>::nodeExist(BSTNode<Type>* node, BSTNode<Type>* searched)
{
    if (node == NULL)
    {
        delete searched;
        return false;
    }
    else if (*searched < *node)
        return nodeExist(node->getLeftChild(), searched);
    else if (*searched > *node)
        return nodeExist(node->getRightChild(), searched);
    else if (*node == *searched)
    {
        delete searched;
        return true;
    }
}

template <typename Type>
BSTNode<Type>* BSTree<Type>::getLeftmostChild(BSTNode<Type>* node)
{
    if (node == NULL)
    {
        return  NULL;
    }
    else if (node->getLeftChild() == NULL)
    {
        return node;
    }
    else
    {
        return getLeftmostChild(node->getLeftChild());
    }
}
