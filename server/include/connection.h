/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** connection
*/

#pragma once

#include "commons.h"
#include "structures.h"

/* Maximum length of a sockets queue. */
#define MAX_LEN_QUEUE 20

/**
 * @brief Listen to the connections to a socket. On error,
 * display a message and exit the program with `84` code.
 *
 * @param sfd File descriptor of the socket.
 */
void listen_con(int sfd);

/**
 * @brief Accept a connection to a socket. On error, display a message.
 *
 * @param sfd File descriptor of the socket.
 * @return `true` if the connection has successfully been accepted.
 * @return `false` if an error occured.
 */
int accept_con(int sfd);

/**
 * @brief Processes connections of a server.
 *
 * @param server Structure containing server informations.
 */
void process_connections(server_t *server);
