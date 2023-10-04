#ifndef TRANSFER_PROBLEM_COMMAND_H
#define TRANSFER_PROBLEM_COMMAND_H

#include "command.h"

class Transfer_problem_command : public Command
{
    QString id_agent_current, id_agent_next, problema;
    QString este_admin;
public:
    Transfer_problem_command(QString s);
    virtual void execute();
    virtual QString get_user_type();
};

#endif // TRANSFER_PROBLEM_COMMAND_H
