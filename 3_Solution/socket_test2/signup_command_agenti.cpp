#include "signup_command_agenti.h"
#include "qsqlquery.h"
#include<iostream>
#include<QDebug>
using namespace  std;

SignUp_command_agenti::SignUp_command_agenti(QString s)
{
    username=s.section('/',1,1);
    parola=s.section('/',2,2);
    nume=s.section('/',3,3);
    prenume=s.section('/',4,4);
    telefon=s.section('/',6,6);
    level=s.section('/',5,5);
}


void SignUp_command_agenti::execute()
{
    QSqlQuery q;
    q.prepare("insert into Users values (?, ?, ?)");
    q.addBindValue(username);
    q.addBindValue(parola);
    q.addBindValue("AGENT");

    if(!q.exec())
    {
        qDebug()<<"Nu s-a reusit inserarea\n";
    }
    else
    {
        qDebug()<<"S-a reusit inserarea\n";
    }

    q.prepare("insert into Agenti values (?, ?, ?, ?, ?)");
    q.addBindValue(nume);
    q.addBindValue(prenume);
    q.addBindValue(level);
    q.addBindValue(telefon);
    q. addBindValue(username);

    if(!q.exec())
    {
        qDebug()<<"Nu s-a reusit inserarea\n";
    }
    else
    {
        qDebug()<<"S-a reusit inserarea\n";
    }
}

QString SignUp_command_agenti::get_user_type()
{
    throw new std::exception;
}
