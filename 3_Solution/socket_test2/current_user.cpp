#include "current_user.h"

Current_user* Current_user::instance=nullptr;

Current_user::Current_user()
{


}

Current_user *Current_user::get_instance()
{
    if(instance==nullptr)
    {
        instance= new Current_user();
    }
    return instance;
}

void Current_user::modify_user(QString u)
{
    user=u;
}

QString Current_user::get_user()
{
    return user;
}
