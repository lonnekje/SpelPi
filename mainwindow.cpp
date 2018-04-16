#include "mainwindow.h"
#include "ui_mainwindow.h"



using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    //setup buttons

    /*QPushButton *Quitbut = new QPushButton("Quit", this);
    Quitbut->move(10,80);
    connect(Quitbut, SIGNAL(clicked(bool)), this, SLOT(QuitSlot()));*/

    QPushButton *Startbut = new QPushButton("<", this);
    Startbut->move(50,80);
    connect(Startbut, SIGNAL(clicked(bool)), this, SLOT(StartSlot()));

    QPushButton *Voorbut = new QPushButton(">", this);
    Voorbut->move(250,80);
    connect(Voorbut, SIGNAL(clicked(bool)), this, SLOT(VoorSlot()));

    QPushButton *Switchbut = new QPushButton("Switch", this);
    Switchbut->move(50,120);
    connect(Switchbut, SIGNAL(clicked(bool)), this, SLOT(SwitchSlot()));

    QPushButton *AFSbut = new QPushButton("afstand", this);
    AFSbut->move(250,120);
    connect(AFSbut, SIGNAL(clicked(bool)), this, SLOT(AFSSlot()));

    //setup threads

    MotorThread = new MotorController();
    CamThread = new CameraHandler();
    GameThread = new GameHandler();




}

void MainWindow::StartSlot(){
    cout << "Start button pressed." << endl;
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    MotorThread->Init();
    MotorThread->run(dir=0);
}

void MainWindow::VoorSlot(){
    cout << "Voor button pressed." << endl;
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    MotorThread->Init();
    MotorThread->run(dir=1);
}

void MainWindow::SwitchSlot(){
    cout << "Switch pressed."<< endl;
    MotorThread->Init();
    MotorThread->stop();
}

void MainWindow::AFSSlot(){
    cout << "Switch pressed."<< endl;
    MotorThread->Init();
    MotorThread->afs();
}

/*void Mainwindow::QuitSlot(){
    cout << "Quit button pressed." << endl;
}*/


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
/*
void MainWindow::on_pushButton_2_clicked()
{
       string inputstate;


       //wiringPiSetup();

       //create new GPIO object to be attached to  GPIO
       GPIOClass* gpio14 = new GPIOClass("14");
       GPIOClass* gpio15 = new GPIOClass("15");
       GPIOClass* gpio18 = new GPIOClass("18");
       GPIOClass* gpio19 = new GPIOClass("19");
       GPIOClass* gpio26 = new GPIOClass("26");

       gpio14->export_gpio();
       gpio15->export_gpio();
       gpio18->export_gpio();
       gpio19->export_gpio();
       gpio26->export_gpio();

       cout << " GPIO pins exported" << endl;

       gpio14->setdir_gpio("out");
       gpio15->setdir_gpio("out");
       gpio18->setdir_gpio("out");
       gpio19->setdir_gpio("out");
       gpio26->setdir_gpio("out");


       cout << " Set GPIO pin directions" << endl;

       //set microstep resolution
       gpio14->setval_gpio("1");
       gpio15->setval_gpio("0");
       gpio18->setval_gpio("1");

       gpio19->setval_gpio("0");

        cout << "Set Microsteps" << endl;

        for(int i=0; i<50; i++){
        gpio26->setval_gpio("1");

        cout << "1e is: " << i << endl;

        sleep(1);
        }

        for(int i=0; i<50;i++)
        {
        gpio19->setval_gpio("1");
        cout << "2e is: " << i << endl;
        sleep(1);
        }

        cout << "klaar"  << endl;

}*/


































