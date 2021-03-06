#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <QMainWindow>
#include <QWidget>
#include "mainwindow.h"
#include <QThread>
#include <pigpio.h>

#define SERVO  5
#define SWITCH4  6
#define SWITCH3 12
#define SWITCH2 13
#define MODE0 14
#define MODE1 15
#define SWITCH1 16
#define MODE2 18

#define DIR2 19
#define STEP2 26

#define DIR1 25
#define STEP1 7

using namespace std;


class MotorController : public QMainWindow
{
    Q_OBJECT
public:
    explicit MotorController(QWidget *parent = 0);
    void CurrentPos();
    void SetPos(int x,int y, int z);
    void run(bool dir);
    void runup(bool dir);
    //static void myInterrupt();
    static void stop();
    static void myInterrupt(int gpio, int level, uint32_t tick);
    void afs();
    void Init();
    void Servoup();
    void Servodown();
    void HomeX();
    void HomeY();
    void Home();
    void Change();
    void Move(int x, int y);

    bool Switch;
    bool stopmotor=false;
    static int count;
    static bool firstTime;
    static int lastx;
    static int lasty;

private:
   // bool switch1 = true;

    int i;
    int x;
    int y;
    int z;
    int MaxStepX = 200;
    int MaxStepY = 200;

    int tempx, tempy;


};



#endif // MOTORCONTROLLER_H
