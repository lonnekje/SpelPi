#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <QMainWindow>
#include <QWidget>
#include "mainwindow.h"
#include <softPwm.h>
//#include "/home/lonneke/sysroot/usr/include/wiringPi.h"

extern "C"{
#include <wiringPi.h>
}

using namespace std;

class MotorController : public QMainWindow
{
    Q_OBJECT
public:
    explicit MotorController(QWidget *parent = 0);
    void CurrentPos();
    void SetPos(int x,int y, int z);
    void run();
    void myInterrupt();


//public slots:
    bool Switch;



private:
   // bool switch1 = true;
    int i;
    int x;
    int y;
    int z;
    int MaxStepX = 200;
    int MaxStepY = 200;
};

#endif // MOTORCONTROLLER_H
