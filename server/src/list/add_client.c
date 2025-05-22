/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune
** File description:
** add_client
*/

#include "list.h"

void init_client_values(client_t **new_client, int cfd)
{
    if (*new_client == NULL)
        return;
    (*new_client)->fd = cfd;
    (*new_client)->logged_in = false;
    (*new_client)->user.USER_NAME = NULL;
    (*new_client)->user.USER_UUID = NULL;
    (*new_client)->user.USER_STATUS = NULL;
    (*new_client)->next = NULL;
}

client_t *add_client(client_t **clients, int cfd)
{
    client_t *node = malloc(sizeof(client_t));
    client_t *it = *clients;

    if (node == NULL)
        return NULL;
    init_client_values(&node, cfd);
    if (*clients == NULL) {
        *clients = node;
        return node;
    }
    while (it->next != NULL)
        it = it->next;
    it->next = node;
    return node;
}
