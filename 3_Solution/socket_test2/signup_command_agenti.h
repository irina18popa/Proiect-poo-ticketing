#ifndef SIGNUP_COMMAND_AGENTI_H
#define SIGNUP_COMMAND_AGENTI_H
#include"command.h"
#include<QString>


class SignUp_command_agenti : public Command
{
    QString nume, prenume, level, telefon, username, parola;
public:
    SignUp_command_agenti(QString s);
    virtual void execute()override;
    virtual QString get_user_type()override;
};

#endif // SIGNUP_COMMAND_AGENTI_H
