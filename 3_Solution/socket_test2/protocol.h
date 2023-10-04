#ifndef PROTOCOL_H
#define PROTOCOL_H
#include<QString>
#include "icommand.h"


class Protocol
{
    static Protocol* ins;
    Protocol();
public:
    static Protocol* get_instance();
    ICommand* get_command (QString s);
};

#endif // PROTOCOL_H
