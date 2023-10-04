QT -= gui
QT += network
QT += core
QT += sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        add_problem_command.cpp \
        command.cpp \
        current_user.cpp \
        database.cpp \
        get_raspuns_command.cpp \
        icommand.cpp \
        login_command.cpp \
        main.cpp \
        my_server.cpp \
        protocol.cpp \
        return_probleme_command.cpp \
        signup_command_agenti.cpp \
        signup_command_client.cpp \
        transfer_problem_command.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    add_problem_command.h \
    command.h \
    current_user.h \
    database.h \
    get_raspuns_command.h \
    icommand.h \
    login_command.h \
    my_server.h \
    protocol.h \
    return_probleme_command.h \
    signup_command_agenti.h \
    signup_command_client.h \
    transfer_problem_command.h
