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

    //networkManager = new QNetworkAccessManager();

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),this, SLOT(onGetData()));
    timer->start(500);







    //setup threads

    MotorThread = new MotorController();
    CamThread = new CameraHandler();
    GameThread = new GameHandler();
    //QNetworkAccessManager *
    networkManager = new QNetworkAccessManager();

   /* GameHandler c;
    c.doConnect();*/

    connect(CamThread, SIGNAL(valueChanged(int, QImage)), this, SLOT(onValueChanged(int, QImage)));


}

void MainWindow::onGetData(){
    //QNetworkAccessManager *networkManager; //= new QNetworkAccessManager();

    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
    networkManager->get(QNetworkRequest(QUrl("http://192.168.129.111:8080/api/users")));
}

int MainWindow::tempfield = 0;
int MainWindow::aantal =0;
int MainWindow::c = 0;


void MainWindow::onResult(QNetworkReply *reply){
    if(!reply->error()){

        QString data = (QString) reply->readAll();\

        if(data.length()!=0){
            qDebug() << "data: "<< data;

    }

        pawn = data[5];
        field.remove(0, 2);

        ffield = data[18];
        sfield = data[19];

        field.append(ffield);
        field.append(sfield);

        fieldvalue = field.toInt();


        pawnvalue = pawn.toInt();


        if(field == "Na"){
            fieldvalue=11;
            qDebug() << "Move to start" ;
              //GameThread->MovePawn(pawnvalue,11);
            }

        if(fieldvalue !=0){

            qDebug() << "Verkregen waardes" << fieldvalue << "c: "<<c;


            switch(c){
            case 0://Wachten op ander resultaat
                if(fieldvalue != tempfield){
                    c = 1;

                }
                break;

            case 1://Check voor  verandering
                if(tempfield == fieldvalue){
                    aantal++;
                    if(aantal == 3){
                        c=2;
                        aantal = 0;
                    }
                }else{
                    aantal = 0;
                }

                break;

            case 2://stuur veldwaarde door
                GameThread->MovePawn(pawnvalue,fieldvalue);
                c=0;
                break;

            default: break;
            }


            tempfield=fieldvalue;
            ffield = 0;
        }

    }

    reply->deleteLater();
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
    //cout << "X&Y"<< endl;
    MotorThread->Init();
    MotorThread->Move(x=34, y=6);
    //MotorThread->Servodown();
}

void MainWindow::Move2Slot(){
   //cout << "Y"<< endl;
    MotorThread->Init();
    MotorThread->Move(x=25, y=5);
   // MotorThread->Servoup();
}


void MainWindow::HomeSlot(){
    MotorThread->Init();
    MotorThread->Move(x=0, y=0);

   /* fieldv= fieldv+2;
    GameThread->MovePawn(pawnv, fieldv);*/
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



void MainWindow::on_pushButton_2_clicked()
{

}
