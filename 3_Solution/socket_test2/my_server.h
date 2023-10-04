#ifndef MY_SERVER_H
#define MY_SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class My_Server : public QObject
{
    Q_OBJECT
public:
    explicit My_Server(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();
    //void ClientDisconnected();
    void ReadyRead();

private:
    QTcpServer *server;

};

#endif // MY_SERVER_H
