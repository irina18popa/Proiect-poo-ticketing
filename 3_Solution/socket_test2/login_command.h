#ifndef LOGIN_COMMAND_H
#define LOGIN_COMMAND_H
#include "command.h"
#include "current_user.h"


class LogIn_command : public Command
{
    QString username, parola, tip_user;
public:
    LogIn_command(QString s);
    virtual void execute()override;
    virtual QString get_user_type()override;
};

#endif // LOGIN_COMMAND_H
