#include "add_problem_command.h"
#include <QDateTime>

Add_problem_command::Add_problem_command(QString s)
{
    descriere=s. section('/',1 ,1);
    status="NEREZOLVAT";
    QDateTime date=QDateTime::currentDateTime();
    QString dateTimeString = date.toString("yyyy-MM-dd hh:mm:ss");
    data_creare=dateTimeString;
}

void Add_problem_command::execute()
{
    Current_user* instance=Current_user::get_instance();
    QSqlQuery q;
    q.prepare("select * from Clienti where Username_signup = ?");
    q.addBindValue(instance->get_user());
    q.exec();
    if(q.next())
    {
        id_client=q.value(0).toString();
        qDebug()<<id_client<<"\n";
    }
    q.prepare("select * from Agenti where Level = '1' order by newid()");
    q.exec();
    if(q.next())
    {
        id_agent=q.value(0).toString();
        qDebug()<<id_agent<<"\n";
    }
}

QString Add_problem_command::get_user_type()
{
    QSqlQuery q;
    q.prepare("insert into Ticket values (?,?,?,?,?,?)");
    q.addBindValue(descriere);
    q.addBindValue(id_client);
    q.addBindValue(id_agent);
    q.addBindValue(status);
    q.addBindValue(data_creare);
    q.addBindValue("-");
    if(q.exec())
    {
        return "TRIMIS";
    }
}
