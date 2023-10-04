#ifndef GET_RASPUNS_COMMAND_H
#define GET_RASPUNS_COMMAND_H

#include "command.h"

class Get_raspuns_command : public Command
{
    QString problema;
    QString raspuns;
public:
    Get_raspuns_command(QString s);
    virtual void execute()override;
    virtual QString get_user_type()override;
};

#endif // GET_RASPUNS_COMMAND_H
