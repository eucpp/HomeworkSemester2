#pragma once

#include <QDebug>
#include "../../tasks6/task6_2/bsTree.h"

/**
  * AVLTree - self-balanced binary search tree.
  * This realization of tree let you add few copies of one element.
  * These copies doesn't really added to the tree,
  * but number of repetitive elements saved in the nodes.
  */

template <typename Type> class AVLTree : public BSTree<Type>
{
public:
    void addValue(Type value);
    void addValue(Type value, unsigned int num);
    void removeValue(Type value);
    void removeValue(Type value, unsigned int num);
    unsigned int elemNum(Type elem)
    {
        BSTNode<Type>* elemNode = getNode(this->root, elem);
        if (elemNode == NULL)
            return 0;
        return elemNode->getNum();
    }
    bool checkBalance()
    {
        return checkBalance(this->root);
    }
private:
    bool checkBalance(BSTNode<Type>* node);
    BSTNode<Type>* getNode(BSTNode<Type>* node, Type searched);
    void addNode(BSTNode<Type>*& dest, BSTNode<Type>* added);
    void removeNode(BSTNode<Type>*& node, BSTNode<Type>* removed);
    /**
      * Few following methods implement algorithms of self-balancing
      */
    void balance(BSTNode<Type>*& node);
    void LLBalance(BSTNode<Type>*& node);
    void LRBalance(BSTNode<Type>*& node);
    void RLBalance(BSTNode<Type>*& node);
    void RRBalance(BSTNode<Type>*& node);
};

template <typename Type>
void AVLTree<Type>::addValue(Type value)
{
    BSTree<Type>::addValue(value);
}

template <typename Type>
void AVLTree<Type>::addValue(Type value, unsigned int num)
{
    BSTNode<Type>* newNode = new BSTNode<Type>(value, NULL, NULL);
    newNode->setNum(num);
    addNode(this->root, newNode);
    this->nodesNum += num;
}
template <typename Type>
void AVLTree<Type>::removeValue(Type value)
{
    BSTree<Type>::removeValue(value);
}

template <typename Type>
void AVLTree<Type>::removeValue(Type value, unsigned int num)
{
    BSTNode<Type>* removedNode = new BSTNode<Type>(value, NULL, NULL);
    removedNode->setNum(num);
    removeNode(this->root, removedNode);
}

template <typename Type>
BSTNode<Type>* AVLTree<Type>::getNode(BSTNode<Type>* node, Type searched)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (searched < node->getValue())
        return getNode(node->getLeftChild(), searched);
    else if (searched > node->getValue())
        return getNode(node->getRightChild(), searched);
    else if (searched == node->getValue())
    {
        return node;
    }
    return NULL;
}

template <typename Type>
bool AVLTree<Type>::checkBalance(BSTNode<Type>* node)
{
    if (node == NULL)
        return true;

    qDebug() << node->getValue();

    int balanceF = node->getBalanceFactor();
    if (balanceF < -1 || balanceF > 1)
        return false;
    if (!checkBalance(node->getLeftChild()))
        return false;
    if (!checkBalance(node->getRightChild()))
        return false;
    return true;
}

template <typename Type>
void AVLTree<Type>::addNode(BSTNode<Type>*& dest, BSTNode<Type>* added)
{
    if (dest != NULL && *dest == *added)
    {
        dest->setNum(dest->getNum() + added->getNum());
    }
    else
        BSTree<Type>::addNode(dest, added);
    balance(dest);
}

template <typename Type>
void AVLTree<Type>::removeNode(BSTNode<Type>*& node, BSTNode<Type>* removed)
{

    if (node != NULL && *node == *removed && node->getNum() > 1)
    {
        if (node->getNum() > removed->getNum())
        {
            node->setNum(node->getNum() - removed->getNum());
            this->nodesNum -= removed->getNum();
        }
        else
        {
            this->nodesNum -= node->getNum() - 1;
            BSTree<Type>::removeNode(node, removed);
        }
    }
    else
        BSTree<Type>::removeNode(node, removed);
    if (node != NULL)
        balance(node);
}

template <typename Type>
void AVLTree<Type>::balance(BSTNode<Type>*& node)
{
    if (node->getBalanceFactor() == 2)
    {
        if (node->getLeftChild()->getBalanceFactor() > 0)
            LLBalance(node);
        else
            LRBalance(node);
    }
    else if (node->getBalanceFactor() == -2)
    {
        if (node->getRightChild()->getBalanceFactor() > 0)
            RLBalance(node);
        else
            RRBalance(node);
    }
}

template <typename Type>
void AVLTree<Type>::LLBalance(BSTNode<Type>*& node)
{
    BSTNode<Type>* newRoot = node->getLeftChild();
    BSTNode<Type>* lrChild = newRoot->getRightChild();
    node->setLeftChild(lrChild);
    newRoot->setRightChild(node);
    node = newRoot;
}

template <typename Type>
void AVLTree<Type>::LRBalance(BSTNode<Type>*& node)
{
    BSTNode<Type>* newRoot = node->getLeftChild()->getRightChild();
    BSTNode<Type>* newRootLChild = node->getLeftChild();
    newRootLChild->setRightChild(newRoot->getLeftChild());
    BSTNode<Type>* newRootRChild = node;
    newRootRChild->setLeftChild(newRoot->getRightChild());
    newRoot->setLeftChild(newRootLChild);
    newRoot->setRightChild(newRootRChild);
    node = newRoot;
}

template <typename Type>
void AVLTree<Type>::RLBalance(BSTNode<Type>*& node)
{
    BSTNode<Type>* newRoot = node->getRightChild()->getLeftChild();
    BSTNode<Type>* newRootRChild = node->getRightChild();
    newRootRChild->setLeftChild(newRoot->getRightChild());
    BSTNode<Type>* newRootLChild = node;
    newRootLChild->setRightChild(newRoot->getLeftChild());
    newRoot->setLeftChild(newRootLChild);
    newRoot->setRightChild(newRootRChild);
    node = newRoot;
}

template <typename Type>
void AVLTree<Type>::RRBalance(BSTNode<Type>*& node)
{
    BSTNode<Type>* newRoot = node->getRightChild();
    BSTNode<Type>* rlChild = newRoot->getLeftChild();
    node->setRightChild(rlChild);
    newRoot->setLeftChild(node);
    node = newRoot;
}
