#include "gamehandler.h"

GameHandler::GameHandler(QObject *parent) :QObject(parent)
{

}

void GameHandler::doConnect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost", 8080);
    //socket->c

    if(socket->waitForConnected(5000))
    {
        cout << "connected" << endl;

        socket->write("GET /api/users\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);



        cout << "Total bytes: " << socket->bytesAvailable() << endl;
        qDebug() << socket->readAll();

        while(socket->bytesAvailable()){
            buffer.append(socket->readAll());
            int packetSize =
        }






        socket->close();

    }
    else
    {
        cout << "Not connected" << endl;
    }

}
