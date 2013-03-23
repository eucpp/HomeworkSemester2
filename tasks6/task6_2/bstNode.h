#pragma once

#include <QStack>

/**
  * @brief Class of nodes of binary search tree.
  *        This class implements functions of control of nodes and comparison operators
  */
template <typename Type> class BSTNode
{
public:
    BSTNode(Type val, BSTNode* leftChild, BSTNode* rightChild): value(val), lChild(leftChild), rChild(rightChild) {}
    ~BSTNode()
    {
        delete lChild;
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
    void setLeftChild(BSTNode* node)
    {
        lChild = node;
    }
    BSTNode*& getLeftChild()
    {
        return lChild;
    }
    void setRightChild(BSTNode* node)
    {
        rChild = node;
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
        nodesStack.push(value);
        if (rChild != NULL)
            rChild->detourNode(nodesStack);
    }

    bool operator==(BSTNode<Type>& node)
    {
        return (value == node.getValue());
    }
    bool operator!=(BSTNode& node)
    {
        return (value != node.value);
    }
    bool operator<(BSTNode& node)
    {
        return (value < node.value);
    }
    bool operator>(BSTNode& node)
    {
        return (value > node.value);
    }
    bool operator<=(BSTNode& node)
    {
        return (value <= node.value);
    }
    bool operator>=(BSTNode& node)
    {
        return (value >= node.value);
    }
private:
    Type value;
    BSTNode<Type>* lChild;
    BSTNode<Type>* rChild;

};

