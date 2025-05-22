/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** response_handlers
*/

#include "structures.h"
#include "logging_client.h"

void handle_login_logout(char **command)
{
    int code = atoi(command[0]);

    switch (code) {
        case LOGIN:
            if (command[1] != NULL && command[2] != NULL) {
                client_event_logged_in(command[1], command[2]);
            }
            break;
        case LOGOUT:
            if (command[1] != NULL && command[2] != NULL) {
                client_event_logged_out(command[1], command[2]);
            }
            break;
    }
}

void handle_usr_list(char **command)
{
    for (int i = 1; command[i] != NULL && command[i + 1] != NULL &&
        command[i + 2] != NULL; i += 3) {
        client_print_users(command[i], command[i + 1], atoi(command[i + 2]));
    }
}

void handle_usr_exist_no_usr(char **command)
{
    int code = atoi(command[0]);

    switch (code) {
        case USR_EXIST:
            if (command[1] != NULL && command[2] != NULL &&
                command[3] != NULL) {
                client_print_user(command[1], command[2], atoi(command[3]));
            }
            break;
        case NO_USR:
            printf("Error try again\n");
            if (command[1] != NULL) {
                client_error_unknown_user(command[1]);
            }
            break;
    }
}

void handle_messages(char **command)
{
    int code = atoi(command[0]);

    switch (code) {
        case MSG_SEND:
            if (command[1] != NULL && command[2] != NULL) {
                client_event_private_message_received(command[1], command[2]);
            }
            break;
        case MSG_EXIST:
            break;
    }
}
//client_private_message_print_messages(command[1], command[2], command[3])
//pour le cas MSG_EXIST
