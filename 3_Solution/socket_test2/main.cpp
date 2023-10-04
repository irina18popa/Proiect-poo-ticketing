#include <QCoreApplication>
#include "database.h"
#include "my_server.h"
#include "protocol.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    My_Server mServer;
    database *db = database::getInstance();
    db->connectDataBase();

//    Protocol* inst=Protocol::get_instance();
//    QString s2="3/nu/0000/jipi/mihnut/04848989/keysight";
//    ICommand* ins2=inst->get_command(s2);
//    ins2->execute();


    return a.exec();
}
