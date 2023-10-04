#ifndef RETURN_PROBLEME_COMMAND_H
#define RETURN_PROBLEME_COMMAND_H
#include<vector>
#include "command.h"
using namespace  std;

class Return_probleme_command : public Command
{
    vector<QString> probleme;
    QString user_curent;
public:
    Return_probleme_command(QString s);
    virtual void execute()override;
    virtual QString get_user_type()override;
    vector<QString> get_probleme_vector();
};

#endif // RETURN_PROBLEME_COMMAND_H
