/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** structures
*/

#pragma once

#include "commons.h"
#include "utils.h"
#include "rfc.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define MAX_ARGS 1024
#define MAX_INPUT_LENGTH 1024
/* Structure containing informations about client. */
typedef struct client_s {
    int con_port;
    in_addr_t con_ip;
    int sockfd;
} client_t;

//connection
int connect_to_server(client_t *client);

//command_gestion
void send_command(int sockfd, char *command);
void receive_response(int sockfd);

//parsing command
char **parse_command(const char *input);

//main_loop
void main_loop(int sockfd);

//handle_response
void handle_response(char **command);

//response_handlers
void handle_login_logout(char **command);
void handle_usr_list(char **command);
void handle_usr_exist_no_usr(char **command);
void handle_messages(char **command);
