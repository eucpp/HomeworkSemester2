#pragma once

#include "iostream"
#include "fstream"
#include <QObject>
#include <QString>
#include <QtTest/QtTest>
#include "parseTree.h"

class ParseTreeTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        tree = new ParseTree;
    }
    void cleanup()
    {
        delete tree;
    }
    void parseTest()
    {
        writeTestFile();
        tree->parse(QString("test.txt"));
    }
    void calcTest()
    {
        writeTestFile();
        tree->parse(QString("test.txt"));
        QCOMPARE(tree->calc(), 4.0);
    }

private:
    void writeTestFile()
    {
        std::ofstream testFile;
        testFile.open("test.txt");
        testFile << "(* (+ 1 1) 2)";
        testFile.close();
    }
    ParseTree* tree;
};
