#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T16:03:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpelPiv1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    motorcontroller.cpp \
    gpioclass.cpp \
    ../rpiPWM1/rpiPWM1.cpp \
    camerahandler.cpp \
    gamehandler.cpp

HEADERS  += mainwindow.h \
    motorcontroller.h \
    gpioclass.h \
    ../rpiPWM1/rpiPWM1.h \
    camerahandler.h \
    gamehandler.h

FORMS    += mainwindow.ui

LIBS += -L/home/lonneke/sysroot/usr/lib \




target.path = /home/pi/
INSTALLS += target
