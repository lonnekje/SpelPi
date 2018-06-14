#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <QTcpSocket>
#include <iostream>
#include <QString>
#include "mainwindow.h"


using namespace std;

class GameHandler : public QObject
{
public:
    explicit GameHandler(QObject *parent =0 );
    void MovePawn(int pawn, int field);
    


private:
    int x,y;
    QTcpSocket *socket;
    QString requestString;
    QByteArray content;
    int bytes =0;
   /* int pawn;
    int field;*/
    int xpos;
    int ypos;


     int table[2][41] ={
         {0, 7,  10, 13, 16, 19, 19, 19, 19, 19, 22, 25, 25, 25, 25, 25, 28, 31, 34, 37, 37, 37, 34, 31, 28, 25, 25, 25, 25, 25, 22, 19, 19, 19, 19, 19, 16, 13, 10,  7,  7 },
         {0, 20, 20, 20, 20, 20, 17, 14, 11,  8,  8,  8, 11, 14, 17, 20, 20, 20, 20, 20, 23, 26, 26, 26, 26, 26, 29, 32, 35, 38, 38, 38, 35, 32, 29, 26, 26, 26, 26, 26, 23 }
     };

     int PawnPos[2][4] ={
         {1, 2, 3, 4},
         {5, 6, 7, 8}
     };




};

#endif // GAMEHANDLER_H
