#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include "/home/lonneke/Hough-Circle-Detector/src/hcd.h"
#include <QImage>



class CameraHandler
{
public:
    CameraHandler();
    void FindCircle();

signals:
    void valueChanged(int, QImage);

private:
    int i;
    int j;
};

#endif // CAMERAHANDLER_H
