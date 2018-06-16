#include "motorcontroller.h"

MotorController::MotorController(QWidget *parent) : QMainWindow(parent)
{

}

void MotorController::stop(){
    cout << "Stop loop" << endl;
    gpioPWM(STEP1, 0);
    gpioPWM(STEP2, 0);
}

void MotorController::Change(){
    stopmotor = true;
}

void MotorController::myInterrupt(int gpio, int level, uint32_t tick){
    switch(level){
    case 1:
        cout << "GPIO " << gpio << " became: " << level << " at tick: "<< tick << endl;
        MotorController mc;
        stop();
        mc.Change();
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

        //Stepper2

        gpioSetMode(DIR2, PI_OUTPUT);
        gpioWrite(DIR2, PI_LOW);
        gpioSetMode(STEP2, PI_OUTPUT);
        gpioWrite(STEP2, PI_LOW);
        gpioSetPWMfrequency(STEP2, 2000);

        //Stepper1

        gpioSetMode(DIR1, PI_OUTPUT);
        gpioWrite(DIR1, PI_LOW);
        gpioSetMode(STEP1, PI_OUTPUT);
        gpioWrite(STEP1, PI_LOW);
        gpioSetPWMfrequency(STEP1, 2000);


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

        //SW3
        gpioSetMode(SWITCH3, PI_INPUT);
        gpioWrite(SWITCH3, PI_LOW);
        gpioSetPullUpDown(SWITCH3, PI_PUD_UP );
        gpioSetISRFunc(SWITCH3, FALLING_EDGE, 200, myInterrupt);

        //SW4
        gpioSetMode(SWITCH4, PI_INPUT);
        gpioWrite(SWITCH4, PI_LOW);
        gpioSetPullUpDown(SWITCH4, PI_PUD_UP );
        gpioSetISRFunc(SWITCH4, FALLING_EDGE, 200, myInterrupt);


        firstTime = false;
        //bool MotorController::stopmotor = false;
      /*  Point last;
        last.setLastLocation(last.lastx=0, last.lasty=0);*/
    }
}

int MotorController::count = 0;
bool MotorController::firstTime = true;
int MotorController::lastx = 0;
int MotorController::lasty = 0;

void MotorController::Servoup(){
    cout << "Servo up" << endl;
      gpioServo(SERVO, 1000);

}

void MotorController::Servodown(){
    cout << "Servo down" << endl;
    gpioServo(SERVO, 2000);

}





void MotorController::Move(int x, int y){

    cout<<"count moves: " << MotorController::count <<endl;
    MotorController::count++;
    MotorController::Init();


cout<<"Start move" << x << y <<endl;

    tempx = x - lastx;
    tempy = y - lasty;

cout<<"Temp xy" << tempx << tempy <<endl;



    if(tempx<0){
        gpioWrite(DIR2, PI_HIGH);
        tempx = tempx * -1;
    }
    else{ gpioWrite(DIR2, PI_LOW);}

    if(tempy<0){
        gpioWrite(DIR1, PI_LOW);
        tempy = tempy * -1;
    }
    else{ gpioWrite(DIR1, PI_HIGH);}

    tempx = tempx*150000;
    tempy = tempy*150000;
    cout<<"end value xy" << tempx << ", "<< tempy <<endl;


    if(tempy==0){
        gpioPWM(STEP2, 50);
        usleep(tempx);
        gpioPWM(STEP2, 0);
    }else if(tempx==0){
        gpioPWM(STEP1, 50);
        usleep(tempy);
        gpioPWM(STEP1, 0);
    }else{
        gpioPWM(STEP1, 50);
        gpioPWM(STEP2, 50);
        usleep(tempy);
        gpioPWM(STEP1, 0);
        gpioPWM(STEP2, 0);
    }

    lastx = x;
    lasty = y;
}

void MotorController::run(bool dir){

    cout << "Checking Dir: "<< dir << endl;

    if(dir==1){
        gpioWrite(DIR2, PI_LOW);
        cout<<"writing DIR2 high"<<endl;
    }
    else{
        gpioWrite(DIR2, PI_HIGH);
        cout<<"writing DIR2 low"<<endl;
    }
    cout << " at tick: "<< gpioTick() << endl;

    gpioPWM(STEP2, 50);

}

void MotorController::runup(bool dir){


    gpioSetMode(21, PI_INPUT);
    gpioWrite(21, PI_LOW);

    cout << "Checking Dir runup: "<< dir << endl;

    if(dir==1){
        gpioWrite(DIR1, PI_LOW);
        cout<<"writing 20 high"<<endl;
    }
    else{
        gpioWrite(DIR1, PI_HIGH);
        cout<<"writing 20 low"<<endl;
    }

    cout << " at tick: "<< gpioTick() << endl;
    gpioPWM(STEP1, 50);

}

void MotorController::afs(){

    gpioWrite(DIR1, PI_LOW);
    gpioPWM(STEP2, 50);
    sleep(2);
    gpioPWM(STEP2, 0);

    //gpioTick

}

/*void MotorController::Servo(int hoog){
    cout << "Servo " << endl;
    for(int i=0; i<1; i++){
        gpioServo(SERVO, 500);
        sleep(2);
        gpioServo(SERVO, 1000);
        sleep(2);

    }
    gpioServo(SERVO, 0);

}
*/
void MotorController::Home(){

    /*HomeX();


    while(stopmotor ==false){

    }
    cout << "After while " << endl;
    HomeY();*/
}

void MotorController::HomeX(){
    cout << "Going Home X " << endl;
    gpioWrite(DIR2, PI_LOW);
    gpioPWM(STEP2, 50);


}


void MotorController::HomeY(){
    cout << "Going Home Y" << endl;
    gpioWrite(DIR2, PI_LOW);
    gpioPWM(STEP1, 50);

}
