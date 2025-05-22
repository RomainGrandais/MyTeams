/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** server
*/

#pragma once

#include "commons.h"
#include "structures.h"

/* Lowest file descriptor usable by the program. */
#define LOWEST_FD 3

/**
 * @brief Run the server on the opened socket.
 *
 * @param server Structure containing server informations.
 */
void run_server(server_t *server);

/**
 * @brief Close properly the server socket and save data.
 *
 * @param server server Structure containing server informations.
 */
void end_server(server_t *server);
