#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QVector>
#include <QPair>

class database
{
private:
    QSqlDatabase db;
    QVector<QPair<QString, QString>> credentials;

    static database *instance;

    database();
    database(const database &obj) = delete;
    database(const database &&obj) = delete;

public:
    static database* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new database();
        }
        return instance;
    }
    void destroy();
    void connectDataBase();
    void readCredentials();

    ~database(){}
};

#endif // DATABASE_H
