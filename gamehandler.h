#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <QTcpSocket>
#include <iostream>
#include <QString>


using namespace std;

class GameHandler : public QObject
{
public:
    explicit GameHandler(QObject *parent =0 );
    void doConnect();
    


private:
    int x,y;
    QTcpSocket *socket;
    QString requestString;
    QByteArray content;
     int bytes =0;




};

#endif // GAMEHANDLER_H
