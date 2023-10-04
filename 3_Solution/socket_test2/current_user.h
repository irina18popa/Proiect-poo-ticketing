#ifndef CURRENT_USER_H
#define CURRENT_USER_H
#include <QString>



class Current_user
{
    QString user;
    static Current_user* instance;
    Current_user();
public:
    static Current_user *get_instance();
    void modify_user(QString u);
    QString get_user();
};

#endif // CURRENT_USER_H
