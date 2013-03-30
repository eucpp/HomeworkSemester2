TEMPLATE = app
CONFIG += console
QT += core testlib

SOURCES += main.cpp \
    abstractOut.cpp \
    fileOut.cpp \
    displayOut.cpp \
    spiralDetour.cpp

HEADERS += \
    abstractOut.h \
    fileOut.h \
    displayOut.h \
    spiralDetour.h \
    spiralDetourTest.h

