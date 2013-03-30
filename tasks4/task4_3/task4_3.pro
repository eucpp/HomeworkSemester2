#-------------------------------------------------
#
# Project created by QtCreator 2013-03-05T22:37:49
#
#-------------------------------------------------

QT       += core gui

TARGET = task4_3
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ../../tasks2/task2_2/calculator.cpp \
    ../../tasks2/task2_2/incorrectExprExc.cpp \
    ../../tasks2/task2_1/accessToEmptyExc.cpp

HEADERS  += widget.h \
    ../../tasks2/task2_2/stackByHeap.h \
    ../../tasks2/task2_2/calculator.h \
    ../../tasks2/task2_2/abstractStack.h \
    ui_widget.h \
    ../../tasks2/task2_2/incorrectExprExc.h \
    ../../tasks2/task2_1/accessToEmptyExc.h

FORMS    += widget.ui
