#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T20:07:52
#
#-------------------------------------------------

QT       += core gui testlib

TARGET = task6_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    operatorNode.cpp \
    ../../tasks2/task2_2/incorrectExprExc.cpp \
    operandNode.cpp \
    parseTree.cpp

HEADERS  += mainwindow.h \
    parseTreeNode.h \
    operatorNode.h \
    ../../tasks2/task2_2/incorrectExprExc.h \
    operandNode.h \
    operatorNodeTest.h \
    operandNodeTest.h \
    parseTree.h \
    parseTreeTest.h

FORMS    += mainwindow.ui
