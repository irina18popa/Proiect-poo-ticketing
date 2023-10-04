#include "my_server.h"
#include<QString>
#include <vector>
#include<signup_command_agenti.h>
#include "return_probleme_command.h"
#include "protocol.h"
using namespace  std;



My_Server::My_Server(QObject *parent) : QObject(parent)
{
    server=new QTcpServer(this);

    connect (server, SIGNAL(newConnection()), this, SLOT (newConnection()));

    quint16 port=4000;

    if(!server->listen(QHostAddress::Any, port))
    {
        qDebug()<<"Server could not start!";
    }
    else
    {
        qDebug()<<"Server started";
    }
}

void My_Server::newConnection()
{
   QTcpSocket* socket = server->nextPendingConnection();
   socket->flush();
   socket->waitForBytesWritten(3000);
   //socket->close();

    /*QTcpSocket* socket = server->nextPendingConnection();
    connect(socket,&QTcpSocket::disconnected,this,&My_Server::disconnected);*/
    connect(socket,&QTcpSocket::readyRead,this,&::My_Server::ReadyRead);
    qInfo() << "Connected" << socket;

}

/*void My_Server::ClientDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Disconnected" << socket;
    qInfo() << "Parent" << socket->parent();

    socket->deleteLater();
}*/

void My_Server::ReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "ReadyReady" << socket;
    QByteArray read=socket->readAll();
    qInfo()<<read;
    QString comm_s = QString::fromLocal8Bit(read);
    Protocol* ins=Protocol::get_instance();
    ICommand*command = ins->get_command(comm_s);
    command->execute();
    if(comm_s.section('/',0,0)=="1" || comm_s.section('/',0,0)=="4" || comm_s.section('/',0,0)=="5" || comm_s.section('/',0,0)=="7")
    {
        QString ret=command->get_user_type();
        socket-> write(ret.toUtf8());
    }
    if(comm_s.section('/',0,0)=="6")
    {
        Return_probleme_command& ref=dynamic_cast<Return_probleme_command&>(*command);
        vector<QString> pb=ref.get_probleme_vector();
        for(auto& it:pb)
        {
            socket->write(it.toLatin1());
        }
    }
}


/*void Server::quit()
{
    server.close();
}


void Server::disconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Disconnected" << socket;
    qInfo() << "Parent" << socket->parent();

    socket->deleteLater();
}*/


