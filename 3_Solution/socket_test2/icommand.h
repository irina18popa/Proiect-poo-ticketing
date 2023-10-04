#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <QString>
#include "QSqlQuery"


class ICommand
{
public:
    ICommand();
    virtual void execute()=0;
    virtual QString get_user_type()=0;

};

#endif // ICOMMAND_H
