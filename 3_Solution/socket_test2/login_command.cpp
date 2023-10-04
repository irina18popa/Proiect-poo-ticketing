#include "login_command.h"
//#include "qsqlquery.h"

LogIn_command::LogIn_command(QString s)
{
    username=s.section('/',1,1);
    parola=s.section('/',2,2);
}

void LogIn_command::execute()
{
    QSqlQuery q;
    Current_user* instance=Current_user::get_instance();
    instance->modify_user(username);
    q.prepare("select * from Users where Username= ? and Password = ?");
    q.addBindValue(username);
    q.addBindValue(parola);
    q.exec();
    if(q.next())
    {
        tip_user=q.value(3).toString();
    }
    else
    {
        tip_user="INEXISTENT";
    }
}

QString LogIn_command::get_user_type()
{
    return tip_user;
}
