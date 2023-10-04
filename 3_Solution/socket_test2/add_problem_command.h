#ifndef ADD_PROBLEM_COMMAND_H
#define ADD_PROBLEM_COMMAND_H
#include "command.h"
#include "current_user.h"


class Add_problem_command : public Command
{
    QString descriere, id_client, id_agent, status, data_creare;
public:
    Add_problem_command(QString s);
    virtual void execute();
    virtual QString get_user_type();
};

#endif // ADD_PROBLEM_COMMAND_H
