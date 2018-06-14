#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "motorcontroller.h"
#include "gamehandler.h"
#include "camerahandler.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include <QUrl>
#include <QNetworkReply>
#include <QTimer>




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

    int fieldvalue;
    int pawnvalue;




    ~MainWindow();
public slots:
    void onValueChanged(int, QImage);

private slots:
    void on_pushButton_clicked();
    void onResult(QNetworkReply*);
    void onGetData();

    //void on_pushButton_2_clicked();
    void StartSlot();
    void SwitchSlot();
    void VoorSlot();
    void AFSSlot();
    void CamSlot();
    void highSlot();
    void lowSlot();
    void Move1Slot();
    void Move2Slot();

    void HomeSlot();

    //void showImg(QImage editmejn);


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    bool dir;
    int pin;
    bool succes;
    int hoog;
    int x,y;

    QString pawn;
    QChar ffield;
    QChar sfield;
    QString field;

    int lastpawn;
    int lastfield;
    int pawnv = 0;
    int fieldv = 0;

    //QPixmap img;
};

#endif // MAINWINDOW_H
