#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <QMainWindow>
#include <QWidget>
#include "mainwindow.h"

using namespace std;

class MotorController : public QMainWindow
{
    Q_OBJECT
public:
    explicit MotorController(QWidget *parent = 0);
    void CurrentPos();
    void SetPos(int x,int y, int z);


signals:

public slots:
    bool Switch;
    void run();


private:
    bool switch1 = true;
    int x;
    int y;
    int z;
    int MaxStepX = 200;
    int MaxStepY = 200;
};

#endif // MOTORCONTROLLER_H
