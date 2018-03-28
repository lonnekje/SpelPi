#include "motorcontroller.h"

MotorController::MotorController(QWidget *parent) : QMainWindow(parent)
{

}

void MotorController::run(){


    if(wiringPiSetup() == -1){
        exit(1);
    }

    pinMode(15, OUTPUT);
    digitalWrite(15, LOW);
    pinMode(16, OUTPUT);
    digitalWrite(16, LOW);
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW);

    pinMode(24, OUTPUT);
    digitalWrite(24, LOW);
    pinMode(25, OUTPUT);
    digitalWrite(25, LOW);
    //sleep(5);

    softPwmCreate(25, 0, 200);
    softPwmWrite(25, 15);
    //sleep(5);


    //pinMode(25, SOFT_PWM_OUTPUT);

   /* for(int l=0; l < 5; l++){
        pwmWrite(25,1);
        sleep(1);
    }*/

    //pwmWrite(25, 50);
    //pwmSetClock(8);
   // pwmSetRange(1024);
   // pwmToneWrite(26, 100);

    /*for(int i=0; i<50; i++){
        for(int l=0; l < 1024; l++){
            pwmWrite(26,1);
            sleep(1);
        }
        for(int l=0; l < 1023; l--){
            pwmWrite(26,1);
            sleep(1);
        }

    }*/


    /*do{
    cout << "Motor is running" << endl;
    sleep(1);
    i++;
    }while(Switch == true || i>10);*/

}

void MotorController::myInterrupt(){
    MotorController::Switch = true;
    sleep(1);
    cout << "interrupt loop, interrupt handled" << endl;
}
