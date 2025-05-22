/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** client
*/

#pragma once

#include "commons.h"
#include "structures.h"

/* Standard size for a read buffer. */
#define READ_BUFF_SIZE 256

/**
 * @brief Process an opened client connection.
 *
 * @param server Structure containing informations about server.
 * @param client Client to process.
 * @return `true` if connection is successfully processed.
 * @return `false` if connection is closed.
 */
bool process_client(server_t *server, client_t *client);
