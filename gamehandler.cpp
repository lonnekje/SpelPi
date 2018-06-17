#include "gamehandler.h"

GameHandler::GameHandler(QObject *parent) :QObject(parent)
{

}

void GameHandler::MovePawn(int pawn, int field)
{

    //move to old pawn pos
    MotorController mc;
    mc.Move(PawnPos[0][pawn], PawnPos[1][pawn]);

    qDebug() << "Old pawn location: " << PawnPos[0][pawn];

    if(field <= 1 || field >=41){
    cout << "Error, wrong field value" << endl;
    }
    else if(PawnPos[2][pawn]==0){
        xpos = velden[field].x;
        ypos = velden[field].y;

        mc.Move(xpos, ypos);
        qDebug()<<"Zet op bord naar: "<<xpos << ypos;
        mc.Servodown();
        PawnPos[0][pawn] = xpos;
        PawnPos[1][pawn] = ypos;
        PawnPos[2][pawn] = field;
    }
    else{
        oldfield = PawnPos[2][pawn];

    //move servo
    mc.Servoup();
    usleep(300);

    //Rangeer uit
    xpos = velden[oldfield].outx;
    ypos = velden[oldfield].outy;
    oldfield = oldfield+1; //Zodat er alleen gechecked wordt voor eenhoek vanaf het volgende veld

    qDebug()<<"Uitgerangeerd naar: "<<xpos << ypos;
    mc.Move(xpos, ypos);

    //Check voor eind of hoek
    for(int i=oldfield; 1; i++){
        if(i==41){
            i=1;
        }
        if(i==field){
            break;
        }

        if(velden[i].rotfield==true){
            xpos = velden[i].rotx;
            ypos = velden[i].roty;
            qDebug()<<"Hoekpunt naar: "<<xpos << ypos;
            mc.Move(xpos, ypos);
        }

    }


    //Rangeer in
    xpos = velden[field].inx;
    ypos = velden[field].iny;
    qDebug()<<"Eindpunt naar: "<<xpos << ypos;
    mc.Move(xpos, ypos);


    xpos = velden[field].x;
    ypos = velden[field].y;
    qDebug()<<"Eindveld naar: "<<xpos << ypos;
    mc.Move(xpos, ypos);

    //Move servo down
    usleep(200);
    mc.Servodown();

    //write new pawn position
    PawnPos[0][pawn] = xpos;
    PawnPos[1][pawn] = ypos;
    PawnPos[2][pawn] = field;

    }

}
