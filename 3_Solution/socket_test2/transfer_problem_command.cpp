#include "transfer_problem_command.h"

Transfer_problem_command::Transfer_problem_command(QString s)
{
    problema=s.section('/',1,1).section('\n',0,0);
}

void Transfer_problem_command::execute()
{
    QSqlQuery q;
    q.prepare("select * from Ticket where Descriere= ?");
    q.addBindValue(problema);
    q.exec();
    if(q.next())
    {
        if(q.value(4).toString()=="REZOLVAT")
        {
            throw std::exception();
        }
        else
        {
            id_agent_current=q.value(3).toString();
        }
    }
    int level;
    q.prepare("select * from Agenti where ID_Agent= ?");
    q.addBindValue(id_agent_current);
    q.exec();
    if(q.next())
    {
        level=q.value(3).toInt();
    }

    if(level<3)
    {
        level++;
        QString level_s=QString::number(level);
        q.prepare("select * from Agenti where Level= ? order by newid()");
        q.addBindValue(level_s);
        q.exec();
        if(q.next())
        {
            id_agent_next=q.value(0).toString();
        }
        q.prepare("update Ticket set ID_Agent= ? where Descriere= ? ");
        q.addBindValue(id_agent_next);
        q.addBindValue(problema);
        if(q.exec())
        {
            qDebug()<<"S-a efectuat transferul problemei\n";
        }
        else
            qDebug()<<"Nu s-a efectuat NIMIIIIIC\n";

    }
    else
    {
        este_admin="ADMIN";
    }
}

QString Transfer_problem_command::get_user_type()
{
    return este_admin;
}


