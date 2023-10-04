#include "signup_command_client.h"

SignUp_command_client::SignUp_command_client(QString s)
{
    username= s.section('/',1 ,1);
    parola = s.section('/',2 ,2);
    nume = s.section('/',3 ,3);
    prenume = s.section('/',4 ,4);
    telefon = s.section('/',5 ,5);
    companie = s.section('/',6 ,6);
}

void SignUp_command_client::execute()
{
    QSqlQuery q;
    q.prepare("insert into Users values (?, ?, ?)");
    q.addBindValue(username);
    q.addBindValue(parola);
    q.addBindValue("CLIENT");
    if(!q.exec())
    {
        qDebug()<<"Nu s-a reusit inserarea\n";
    }
    else
    {
        qDebug()<<"S-a reusit inserarea\n";
    }

    q.prepare("insert into Clienti values (?, ?, ?, ?, ?)");
    q.addBindValue(nume);
    q.addBindValue(prenume);
    q.addBindValue(telefon);
    q.addBindValue(companie);
    q.addBindValue(username);
    if(!q.exec())
    {
        qDebug()<<"Nu s-a reusit inserarea\n";
    }
    else
    {
        qDebug()<<"S-a reusit inserarea\n";
    }
}

QString SignUp_command_client::get_user_type()
{
    throw new std::exception;
}
