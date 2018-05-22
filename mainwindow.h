#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "gpioclass.h"
#include "motorcontroller.h"
#include "gamehandler.h"
#include "camerahandler.h"




namespace Ui {
class MainWindow;
}

class MotorController;
class CameraHandler;
class GameHandler;

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    //using QWidget::QObject;
    explicit MainWindow(QWidget *parent = 0);



    MotorController *MotorThread;
    CameraHandler *CamThread;
    GameHandler *GameThread;




    ~MainWindow();
public slots:
    void onValueChanged(int, QImage);

private slots:
    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();
    void StartSlot();
    void SwitchSlot();
    void VoorSlot();
    void AFSSlot();
    void CamSlot();
    void highSlot();
    void lowSlot();
    void ServoSlot();
    void Servo2Slot();
    void HomeSlot();

    //void showImg(QImage editmejn);


private:
    Ui::MainWindow *ui;
    bool dir;
    int pin;
    bool succes;
    int hoog;
    //QPixmap img;
};

#endif // MAINWINDOW_H
