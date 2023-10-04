#include "database.h"

database *database::instance = nullptr;
database::database()
{
}

void database::destroy()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

void database::connectDataBase()
{
    QString servername="localhost";
    QString dbname="FixFinder";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();
    QString dsn = QString("DRIVER={ODBC Driver 17 for SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername,dbname);
    db.setDatabaseName(dsn);
    if(db.open())
        qDebug()<<"Open completed\n";
    else
    {
        qDebug()<<"OPEN FAILED\n"<<db.lastError().text();
        exit(0);
    }
}



//void database::readCredentials()
//{
//     QSqlQuery query ;
//     query.exec("SELECT * FROM Agenti");

//     while(query.next())
//        {
//           QString str = query.value(1).toString()+query.value(2).toString();
//           QStringList l = str.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

//           QPair<QString, QString> pair;
//           pair.first = l.value(0);
//           pair.second = l.value(1);

//           credentials.push_back(pair);
//        }
//}
