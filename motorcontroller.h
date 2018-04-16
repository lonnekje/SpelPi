#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <QMainWindow>
#include <QWidget>
#include "mainwindow.h"
#include <softPwm.h>
//#include "/home/lonneke/sysroot/usr/include/wiringPi.h"

/*extern "C"{
#include <wiringPi.h>
}*/

#include <pigpio.h>

#define GPIO5  5
#define GPIO6  6
#define SWITCH3 12
#define SWITCH2 13
#define MODE0 14
#define MODE1 15
#define SWITCH1 16
#define MODE2 18
#define GPIO19 19
#define GPIO20 20
#define GPIO21 21
#define GPIO26 26




using namespace std;



class MotorController : public QMainWindow
{
    Q_OBJECT
public:
    explicit MotorController(QWidget *parent = 0);
    void CurrentPos();
    void SetPos(int x,int y, int z);
    void run(bool dir);
    //static void myInterrupt();
    static void stop();
    static void myInterrupt(int gpio, int level, uint32_t tick);
    void afs();
    void Init();

    bool Switch;

private:
   // bool switch1 = true;
    int i;
    int x;
    int y;
    int z;
    int MaxStepX = 200;
    int MaxStepY = 200;
    bool firstTime = true;
};

#endif // MOTORCONTROLLER_H
