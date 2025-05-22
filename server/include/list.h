/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune
** File description:
** list
*/

#pragma once

#include "commons.h"
#include "structures.h"

/**
 * @brief Add a client to a chained list.
 *
 * @param clients A chained list of clients.
 * @param cfd File descriptor of the client to add.
 * @return The added client or `NULL` in case of error.
 */
client_t *add_client(client_t **clients, int cfd);

/**
 * @brief Remove a client from a chained list.
 *
 * @param clients A chained list of clients.
 * @param cfd File descriptor of the client to remove.
 */
void remove_client(client_t **clients, int cfd);

/**
 * @brief Remove the last client from a clients list.
 *
 * @param clients Chained list of clients.
 */
void remove_last_client(client_t **clients);
