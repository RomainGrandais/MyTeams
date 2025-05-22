/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** handle_response
*/

#include "structures.h"
#include "logging_client.h"

void cut_switch(char **command, int response_code)
{
    switch (response_code) {
        case USR_EXIST:
            handle_usr_exist_no_usr(command);
            break;
        case NO_USR:
            handle_usr_exist_no_usr(command);
            break;
        case MSG_SEND:
            handle_messages(command);
            break;
        case MSG_EXIST:
            handle_messages(command);
            break;
    }
}

void handle_response(char **command)
{
    int response_code;

    if (command[0] == NULL)
        return;
    response_code = atoi(command[0]);
    switch (response_code) {
        case LOGIN:
            handle_login_logout(command);
            break;
        case LOGOUT:
            handle_login_logout(command);
            break;
        case USR_LIST:
            handle_usr_list(command);
            break;
    }
    cut_switch(command, response_code);
}
