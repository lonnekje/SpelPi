#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

//#include <QImage>
//#include "core/core.hpp"
//#include "opencv2/highgui.hpp"

#include "mainwindow.h"
#include <QMainWindow>
#include <QWidget>
#include <QObject>
//#include "/home/lonneke/Hough-Circle-Detector/src/hcd.h"

#include "math.h"
#include "stdint.h"





using namespace std;

class CameraHandler : public QWidget
{
    Q_OBJECT
public:

    CameraHandler();
    void FindCircle();

signals:
    void valueChanged(int, QImage);

private slots:


private:
    int i=0;
    int a=30;
    int b=20;

    //cv::Mat frame;
};

#endif // CAMERAHANDLER_H
