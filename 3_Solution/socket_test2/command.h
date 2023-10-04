#ifndef COMMAND_H
#define COMMAND_H
#include"icommand.h"


class Command : public ICommand
{
public:
    Command();
    virtual void execute()override;
    virtual QString get_user_type()=0;

};

#endif // COMMAND_H
