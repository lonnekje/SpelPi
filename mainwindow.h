#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    explicit MainWindow(QWidget *parent = 0);



    MotorController *MotorThread;
    CameraHandler *CamThread;
    GameHandler *GameThread;




    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();
    void StartSlot();
    void SwitchSlot();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
