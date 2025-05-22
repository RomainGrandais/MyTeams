/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune
** File description:
** remove_client
*/

#include "database.h"
#include "list.h"
#include "logging_server.h"
#include "socket.h"

void remove_client(client_t **clients, int cfd)
{
    client_t *it = *clients;
    client_t *prev = NULL;

    if (*clients == NULL)
        return;
    while (it->next != NULL && it->fd != cfd) {
        prev = it;
        it = it->next;
    }
    server_event_user_logged_out(it->user.USER_UUID);
    if (it->fd == cfd) {
        if (it == *clients)
            *clients = NULL;
        if (prev != NULL)
            prev->next = it->next;
        free(it);
    }
}

void remove_last_client(client_t **clients)
{
    client_t *it = *clients;
    client_t *prev = NULL;

    if (*clients == NULL)
        return;
    while (it->next != NULL) {
        prev = it;
        it = it->next;
    }
    server_event_user_logged_out(it->user.USER_UUID);
    if (it == *clients)
        *clients = NULL;
    if (prev != NULL)
        prev->next = NULL;
    free(it);
}
