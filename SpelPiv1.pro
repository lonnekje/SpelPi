#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T16:03:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpelPiv1
TEMPLATE = app

INCLUDEPATH +=  /home/lonneke/sysroot/usr/include \
                /home/lonneke/sysroot/usr/include/arm-linux-gnueabihf/
#                /home/lonneke/sysroot/usr/lib


LIBS += -L/home/lonneke/sysroot/usr/lib -lwiringPi \


SOURCES += main.cpp\
        mainwindow.cpp \
    motorcontroller.cpp \
    gpioclass.cpp \
    camerahandler.cpp \
    gamehandler.cpp

HEADERS  += mainwindow.h \
    motorcontroller.h \
    gpioclass.h \
    camerahandler.h \
    gamehandler.h

FORMS    += mainwindow.ui




target.path = /home/pi/
INSTALLS += target
