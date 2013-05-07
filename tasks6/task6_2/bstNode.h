#pragma once

#include <QtGlobal>
#include <QStack>

/**
  * @brief Class of nodes of binary search tree.
  *        This class implements functions of control of nodes and comparison operators
  */
template <typename Type> class BSTNode
{
public:
    BSTNode(Type val, BSTNode<Type>* leftChild, BSTNode<Type>* rightChild):
        value(val),
        lChild(leftChild),
        rChild(rightChild),
        num(1)
    {
        recalcHeight();
    }
    ~BSTNode()
    {
        if (lChild != NULL)
            delete lChild;
        if (rChild != NULL)
            delete rChild;
    }
    void setValue(Type val)
    {
        value = val;
    }
    Type getValue()
    {
        return value;
    }
    void setLeftChild(BSTNode<Type>* node)
    {
        lChild = node;
        recalcHeight();
    }
    BSTNode*& getLeftChild()
    {
        return lChild;
    }
    void setRightChild(BSTNode<Type>* node)
    {
        rChild = node;
        recalcHeight();
    }
    BSTNode*& getRightChild()
    {
        return rChild;
    }
    bool isLeaf()
    {
        return (lChild == NULL && rChild == NULL);
    }
    /**
      * @brief Method used for detour struct of nodes
      *        It adds value of left & right child recursively to the stack (if they exist)
      *        and current value between children
      */
    void detourNode(QStack<Type>& nodesStack)
    {
        if (lChild != NULL)
            lChild->detourNode(nodesStack);
        unsigned int n = num;
        while (n > 0)
        {
            nodesStack.push(value);
            --n;
        }
        if (rChild != NULL)
            rChild->detourNode(nodesStack);
    }
    unsigned int getNum()
    {
        return num;
    }
    void setNum(unsigned int n)
    {
        num = n;
    }
    unsigned int getHeight()
    {
        return height;
    }
    void setHeight(unsigned int h)
    {
        height = h;
    }
    void recalcHeight();
    int getBalanceFactor();
    void operator++()
    {
        ++num;
    }
    void operator--()
    {
        --num;
    }

    bool operator==(BSTNode<Type>& node)
    {
        return (value == node.getValue());
    }
    bool operator!=(BSTNode<Type>& node)
    {
        return (value != node.value);
    }
    bool operator<(BSTNode<Type>& node)
    {
        return (value < node.value);
    }
    bool operator>(BSTNode<Type>& node)
    {
        return (value > node.value);
    }
    bool operator<=(BSTNode<Type>& node)
    {
        return (value <= node.value);
    }
    bool operator>=(BSTNode<Type>& node)
    {
        return (value >= node.value);
    }
private:
    Type value;
    BSTNode<Type>* lChild;
    BSTNode<Type>* rChild;
    unsigned int num;
    unsigned int height;
};

template <typename Type>
void BSTNode<Type>::recalcHeight()
{
    if (lChild == NULL && rChild == NULL)
        height = 1;
    else if (lChild == NULL)
        height = rChild->height + 1;
    else if (rChild  == NULL)
        height = lChild->height + 1;
    else
        height = qMax(lChild->height, rChild->height) + 1;
}
template <typename Type>
int BSTNode<Type>::getBalanceFactor()
{
    if (lChild == NULL && rChild == NULL)
        return 0;
    else if (lChild == NULL)
        return -rChild->height;
    else if (rChild == NULL)
        return lChild->height;
    else
        return lChild->height - rChild->height;
}
