#include "mainwindow.h"
#include "ui_mainwindow.h"



using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);




    QPixmap mejn (":/mejn1.jpg");
    ui->Label_picture->setPixmap(mejn);

    //QPixmap editmejn(mejn);
   // ui->Edit_Label->setPixmap(editmejn);

    //setup buttons
    QPushButton *Startbut = new QPushButton("<", this);
    Startbut->move(50,80);
    connect(Startbut, SIGNAL(clicked(bool)), this, SLOT(StartSlot()));

    QPushButton *Voorbut = new QPushButton(">", this);
    Voorbut->move(250,80);
    connect(Voorbut, SIGNAL(clicked(bool)), this, SLOT(VoorSlot()));

    QPushButton *highbut = new QPushButton("^", this);
    highbut->move(50,120);
    connect(highbut, SIGNAL(clicked(bool)), this, SLOT(highSlot()));

    QPushButton *lowbut = new QPushButton("v", this);
    lowbut->move(250,120);
    connect(lowbut, SIGNAL(clicked(bool)), this, SLOT(lowSlot()));

    QPushButton *Switchbut = new QPushButton("Switch", this);
    Switchbut->move(50,160);
    connect(Switchbut, SIGNAL(clicked(bool)), this, SLOT(SwitchSlot()));

    QPushButton *AFSbut = new QPushButton("afstand", this);
    AFSbut->move(250,160);
    connect(AFSbut, SIGNAL(clicked(bool)), this, SLOT(AFSSlot()));

    QPushButton *Cambut = new QPushButton("Cam", this);
    Cambut->move(50,200);
    connect(Cambut, SIGNAL(clicked(bool)), this, SLOT(CamSlot()));

    QPushButton *Movebut1 = new QPushButton("Move1", this);
    Movebut1->move(250,200);
    connect(Movebut1, SIGNAL(clicked(bool)), this, SLOT(Move1Slot()));

    QPushButton *Movebut2 = new QPushButton("Move2", this);
    Movebut2->move(50,240);
    connect(Movebut2, SIGNAL(clicked(bool)), this, SLOT(Move2Slot()));

    QPushButton *Homebut = new QPushButton("Home", this);
    Homebut->move(250,240);
    connect(Homebut, SIGNAL(clicked(bool)), this, SLOT(HomeSlot()));




    //setup threads

    MotorThread = new MotorController();
    CamThread = new CameraHandler();
    GameThread = new GameHandler();

    GameHandler c;
    c.doConnect();

    connect(CamThread, SIGNAL(valueChanged(int, QImage)), this, SLOT(onValueChanged(int, QImage)));


}

void MainWindow::StartSlot(){
    cout << "Start button pressed." << endl;
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    MotorThread->Init();
    MotorThread->run(dir=1);
}

void MainWindow::VoorSlot(){
    cout << "Voor button pressed." << endl;
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    MotorThread->Init();
    MotorThread->run(dir=0);
}

void MainWindow::highSlot(){
    cout << "Start button pressed." << endl;
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    MotorThread->Init();
    MotorThread->runup(dir=0);
}

void MainWindow::lowSlot(){
    cout << "Voor button pressed." << endl;
    setenv("WIRINGPI_GPIOMEM", "1", 1);
    MotorThread->Init();
    MotorThread->runup( dir=1);
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

void MainWindow::CamSlot(){
    cout << "Cam."<< endl;
    CamThread->FindCircle();
}

/*void MainWindow::ServoSlot(){
    cout << "Servo"<< endl;
    MotorThread->Init();
    MotorThread->Servo(hoog=180);
}

void MainWindow::Servo2Slot(){
    cout << "Servo"<< endl;
    MotorThread->Init();
    MotorThread->Servo(hoog=80);
}*/

void MainWindow::Move1Slot(){
    cout << "Move1"<< endl;
    MotorThread->Init();
    MotorThread->Move(x=4, y=2);
}

void MainWindow::Move2Slot(){
    cout << "Homemove2"<< endl;
    MotorThread->Init();
    MotorThread->Move(x=10, y=6);
}


void MainWindow::HomeSlot(){
    cout << "Home"<< endl;
    MotorThread->Init();
    MotorThread->Move(x=0,y=0);
}

void MainWindow::onValueChanged(int count, QImage img){
    ui->Textlabel->setText(QString::number(count));
    ui->Edit_Label->setPixmap(QPixmap::fromImage(img));
}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{

}


