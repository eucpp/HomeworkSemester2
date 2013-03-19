#include "parseTree.h"

ParseTree::ParseTree()
{
    root = NULL;
}
ParseTree::~ParseTree()
{
    delete root;
}

bool isOperator(QChar ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void ParseTree::parse(QString filename) throw(IncorrectExprExc)
{
    std::ifstream in;
    in.open(filename.toStdString().c_str());
    parse(in, root);
    in.close();
}

void ParseTree::parse(std::ifstream& in, ParseTreeNode*& currNode) throw(IncorrectExprExc)
{
    QChar ch = QChar(in.get());
    while (!ch.isNumber() && !isOperator(ch) && !in.eof())
    {
        ch = QChar(in.get());
    }
    if (in.eof())
    {
        in.close();
        throw IncorrectExprExc("Unexpected end of expression");
    }
    else
    {
        ParseTreeNode* newNode = NULL;
        if (ch.isNumber())
        {
            in.putback(ch.toAscii());
            int operand;
            in >> operand;
            newNode = new OperandNode(operand);
        }
        else
        {
            newNode = new OperatorNode(NULL, NULL, ch);
        }
        currNode = newNode;
        if (isOperator(ch))
        {
            parse(in, currNode->getLeftChild());
            parse(in, currNode->getRightChild());
        }
    }
}
double ParseTree::calc()
{
    if (root == NULL)
        return 0;
    return root->calc();
}
void ParseTree::print(QTextEdit* out)
{
    if (root == NULL)
        return;
    root->print(out);
}
