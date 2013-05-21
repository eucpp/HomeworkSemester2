#-------------------------------------------------
#
# Project created by QtCreator 2013-05-21T13:44:39
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = final
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    IntComparator.cpp \
    doubleComparator.cpp

HEADERS += \
    comparator.h \
    sorter.h \
    IntComparator.h \
    sorterTest.h \
    doubleComparator.h
