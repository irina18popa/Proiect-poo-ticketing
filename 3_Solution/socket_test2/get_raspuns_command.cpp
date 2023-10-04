#include "get_raspuns_command.h"

Get_raspuns_command::Get_raspuns_command(QString s)
{
    problema=s.section('/',1,1).section('\n',0,0);
    raspuns=s.section('/',2,2);
}

void Get_raspuns_command::execute()
{
    QSqlQuery q;
    q.prepare("update Ticket set Raspuns= ? where Descriere= ?");
    q.addBindValue(raspuns);
    q.addBindValue(problema);
    if(q.exec())
    {
        qDebug()<<"Raspunsul a fost inserat cu succes\n";

    }

    q.prepare("update Ticket set Status= ? where Descriere= ?");
    q.addBindValue("REZOLVAT");
    q.addBindValue(problema);
    if(q.exec())
    {
        qDebug()<<"Statusul a fost schimbat cu succes\n";

    }
}

QString Get_raspuns_command::get_user_type()
{
    return "TRIMIS";
}
