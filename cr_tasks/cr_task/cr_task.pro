#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:52:25
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = cr_task
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    robot.cpp \
    robotpanel.cpp \
    command.cpp

HEADERS += \
    robot.h \
    robotpanel.h \
    command.h \
    bluetoothcommand.h \
    usbcommand.h \
    RobotPanelTest.h
