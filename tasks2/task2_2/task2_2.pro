
TEMPLATE = app
CONFIG += console
QT += core testlib

SOURCES += main.cpp \
    calculator.cpp \
    ../task2_1/accessToEmptyExc.cpp \
    incorrectExprExc.cpp

HEADERS += \
    abstractStack.h \
    stackByHeap.h \
    ../task2_1/listElement.h \
    calculator.h \
    stackByArray.h \
    ../task2_1/accessToEmptyExc.h \
    incorrectExprExc.h \
    stackTest.h \
    stackByHeapTest.h \
    stackByArrayTest.h

