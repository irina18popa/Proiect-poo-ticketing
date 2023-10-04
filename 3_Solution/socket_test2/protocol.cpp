#include "protocol.h"
#include "signup_command_agenti.h"
#include "login_command.h"
#include "signup_command_client.h"
#include "add_problem_command.h"
#include "current_user.h"
#include "transfer_problem_command.h"
#include "return_probleme_command.h"
#include "get_raspuns_command.h"

Protocol* Protocol::ins=nullptr;


Protocol::Protocol()
{

}

Protocol *Protocol::get_instance()
{
    if(ins==nullptr)
    {
        ins=new Protocol();
    }
    return ins;
}

ICommand *Protocol::get_command(QString s)
{
    QString id=s.section('/',0,0);

    if(id=="1")
    {
        return new LogIn_command(s);
    }
    else if(id=="2")
    {
        return new SignUp_command_agenti(s);
    }
    else if(id=="3")
    {
        return new SignUp_command_client(s);
    }
    else if(id=="4")
    {
        return new Add_problem_command(s);
    }
    else if(id=="5")
    {
        return new Transfer_problem_command(s);
    }
    else if(id=="6")
    {
        return new Return_probleme_command(s);
    }
    else if(id=="7")
    {
        return new Get_raspuns_command(s);
    }
}
