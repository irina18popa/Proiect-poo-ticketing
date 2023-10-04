#ifndef SIGNUP_COMMAND_CLIENT_H
#define SIGNUP_COMMAND_CLIENT_H
#include "command.h"


class SignUp_command_client : public Command
{
    QString nume, prenume, telefon, companie, username, parola;
public:
    SignUp_command_client(QString s);
    virtual void execute()override;
    virtual QString get_user_type()override;
};

#endif // SIGNUP_COMMAND_CLIENT_H
