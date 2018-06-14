#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T16:03:08
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpelPiv1
TEMPLATE = app

CONFIG -= no-pkg-config
CONFIG += link_pkgconfig


INCLUDEPATH +=  /home/lonneke/sysroot/usr/include \
                /home/lonneke/sysroot/usr/include/opencv2 \
                /home/lonneke/sysroot/usr/include/arm-linux-gnueabihf/
                /home/lonneke/sysroot/usr/include/arm-linux-gnueabihf/gnu/

#                /home/lonneke/sysroot/usr/lib


LIBS += -L/home/lonneke/sysroot/usr/lib -lwiringPi \
                                        -lpigpio \

        -L/home/lonneke/sysroot/usr/opencv  #-lopencv_imgproc\
                                            #-lopencv_highgui\



SOURCES += main.cpp\
        mainwindow.cpp \
    motorcontroller.cpp \
    camerahandler.cpp \
    gamehandler.cpp
    #../Hough-Circle-Detector/src/hcd.cpp \


HEADERS  += mainwindow.h \
    motorcontroller.h \
    camerahandler.h \
    gamehandler.h \
    #../Hough-Circle-Detector/src/hcd.h \
    app.h \
    ../sysroot/usr/include/opencv2/highgui/highgui.hpp \
    ../sysroot/usr/include/opencv2/imgproc/imgproc.hpp \
    ../sysroot/usr/include/opencv2/videoio/videoio.hpp \
    ../sysroot/usr/include/opencv2/core/core.hpp


FORMS    += mainwindow.ui




target.path = /home/pi/
INSTALLS += target

RESOURCES += \
    photos.qrc

DISTFILES += \
    README.md
