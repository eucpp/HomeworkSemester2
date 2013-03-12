#-------------------------------------------------
#
# Project created by QtCreator 2013-03-12T17:38:31
#
#-------------------------------------------------

QT       += core gui testlib

TARGET = task5_1
TEMPLATE = app


SOURCES += main.cpp\
        hashTableManager.cpp \
    sumHashFunction.cpp \
    ../../tasks2/task2_1/accessToEmptyExc.cpp

HEADERS  += hashTableManager.h \
    hashTable.h \
    sumHashFunction.h \
    hashFunction.h \
    sumHashFunctionTest.h \
    ../../tasks2/task2_1/singleLinkedList.h \
    ../../tasks2/task2_1/listElement.h \
    ../../tasks2/task2_1/accessToEmptyExc.h \
    ../../tasks2/task2_1/abstractList.h

FORMS    += hashTableManager.ui
