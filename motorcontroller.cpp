#include "motorcontroller.h"

MotorController::MotorController(QWidget *parent) : QMainWindow(parent)
{

}

void MotorController::stop(){
    cout << "Stop loop" << endl;
    gpioPWM(GPIO26, 0);
}

void MotorController::myInterrupt(int gpio, int level, uint32_t tick){
    switch(level){
    case 1:
        cout << "GPIO " << gpio << " became: " << level << " at tick: "<< tick << endl;
        stop();
        cout << "interrupt loop, interrupt handled" << endl;
        break;
    }


}

void MotorController::Init(){


    if(firstTime == true){


        cout << "Init Loop" << endl;

        if(gpioInitialise() == -1){
            exit(1);
        }
        //mode
        gpioSetMode(MODE0, PI_OUTPUT);
        gpioWrite(MODE0, PI_HIGH);
        gpioSetMode(MODE1, PI_OUTPUT);
        gpioWrite(MODE1, PI_HIGH);
        gpioSetMode(MODE2, PI_OUTPUT);
        gpioWrite(MODE2, PI_LOW);

        //Stepper1

        gpioSetMode(GPIO19, PI_OUTPUT);
        gpioWrite(GPIO19, PI_LOW);
        gpioSetMode(GPIO26, PI_OUTPUT);
        gpioWrite(GPIO26, PI_LOW);
        gpioSetPWMfrequency(GPIO26, 2000);

        //SW1
        gpioSetMode(SWITCH1, PI_INPUT);
        gpioWrite(SWITCH1, PI_LOW);
        gpioSetPullUpDown(SWITCH1, PI_PUD_UP );
        gpioSetISRFunc(SWITCH1, FALLING_EDGE, 200, myInterrupt);

        //SW2
        gpioSetMode(SWITCH2, PI_INPUT);
        gpioWrite(SWITCH2, PI_LOW);
        gpioSetPullUpDown(SWITCH2, PI_PUD_UP );
        gpioSetISRFunc(SWITCH2, FALLING_EDGE, 200, myInterrupt);


        firstTime = false;
    }
}

void MotorController::run(bool dir){

    cout << "Checking Dir: "<< dir << endl;

    if(dir==1){
        gpioWrite(GPIO19, PI_HIGH);
        cout<<"writing 19 high"<<endl;
    }
    else{
        gpioWrite(GPIO19, PI_LOW);
        cout<<"writing 19 low"<<endl;
    }

    gpioPWM(GPIO26, 50);

}

void MotorController::afs(){

    gpioWrite(GPIO19, PI_HIGH);
    gpioPWM(GPIO26, 50);
    sleep(2);
    gpioPWM(GPIO26, 0);

    //gpioTick

}







