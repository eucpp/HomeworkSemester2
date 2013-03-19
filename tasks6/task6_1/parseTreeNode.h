#pragma once

#include "../../tasks2/task2_2/incorrectExprExc.h"
#include <QTextEdit>

/**
  * @brief This class describes the nodes of parse tree.
  *        These nodes can print yourself and recursively calculate the expression which they contained
  */
class ParseTreeNode
{
public:
    //ParseTreeNode(): leftChild(NULL), rightChild(NULL) {}
    ParseTreeNode(ParseTreeNode* lChild, ParseTreeNode* rChild): leftChild(lChild), rightChild(rChild) {}
    virtual ~ParseTreeNode()
    {
        delete leftChild;
        delete rightChild;
    }
    virtual void print(QTextEdit* out) = 0;
    virtual double calc() throw(IncorrectExprExc) = 0;
    void setLeftChild(ParseTreeNode* node)
    {
        leftChild = node;
    }
    ParseTreeNode*& getLeftChild()
    {
        return leftChild;
    }
    void setRightChild(ParseTreeNode* node)
    {
        rightChild = node;
    }
    ParseTreeNode*& getRightChild()
    {
        return rightChild;
    }
protected:
    ParseTreeNode* leftChild;
    ParseTreeNode* rightChild;
};

