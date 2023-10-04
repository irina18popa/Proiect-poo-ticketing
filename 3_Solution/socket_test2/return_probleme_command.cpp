#include "return_probleme_command.h"
#include "current_user.h"

Return_probleme_command::Return_probleme_command(QString s)
{
    Current_user* inst=Current_user::get_instance();
    user_curent=inst->get_user();
}

void Return_probleme_command::execute()
{
    QString tip_user;
    QSqlQuery q;
    q.prepare("select * from Users where Username = ?");
    q.addBindValue(user_curent);
    q.exec();
    if(q.next())
    {
        tip_user=q.value(3).toString();
    }
    QString id_user_current;
    if(tip_user=="AGENT")
    {
        q.prepare("select * from Agenti where Username_signup = ?");
        q.addBindValue(user_curent);
        q.exec();
        if(q.next())
        {
            id_user_current=q.value(0).toString();
        }

        q.prepare("select * from Ticket where ID_Agent = ?");
        q.addBindValue(id_user_current);
        q.exec();
        while(q.next())
        {
            probleme.push_back(q.value(1).toString()+"\n"+user_curent+": "+q.value(6).toString()+"/");
        }
    }
    else
    {
        q.prepare("select * from Clienti where Username_signup = ?");
        q.addBindValue(user_curent);
        q.exec();
        if(q.next())
        {
            id_user_current=q.value(0).toString();
        }

        q.prepare("select * from Ticket where ID_Client = ?");
        q.addBindValue(id_user_current);
        q.exec();
        while(q.next())
        {
            QString agent_id, username_agent;
            agent_id=q.value(3).toString();
            QSqlQuery q2;
            q2.prepare("select * from Agenti where ID_Agent = ?");
            q2.addBindValue(agent_id);
            q2.exec();
            if(q2.next())
            {
                username_agent=q2.value(5).toString();
            }
            probleme.push_back(q.value(1).toString()+"\n"+username_agent+": "+q.value(6).toString()+"/");
        }
    }
}

QString Return_probleme_command::get_user_type()
{
    throw std::exception();
}

vector<QString> Return_probleme_command::get_probleme_vector()
{
    return probleme;
}
