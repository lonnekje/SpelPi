#include "gamehandler.h"

GameHandler::GameHandler(QObject *parent) :QObject(parent)
{

}

void GameHandler::MovePawn(int pawn, int field)
{

    //move to old pawn pos
    MotorController mc;
    mc.Move(PawnPos[0][pawn], PawnPos[1][pawn]);

    //move servo


    //lookup coordinate
    xpos = table[0][field];
    ypos = table[1][field];

    cout << "coort: " << xpos << ","<< ypos << endl;
    cout << "pawn: " << pawn << endl;
    cout << "field: " << field << endl;

    //move to new pawn position

    mc.Move(xpos, ypos);

    //write down new location
    PawnPos[0][pawn] = xpos;
    PawnPos[1][pawn] = ypos;

    cout << "xpawn: " << PawnPos[0][pawn] << endl;
    cout << "ypawn: " << PawnPos[1][pawn] << endl;




}
