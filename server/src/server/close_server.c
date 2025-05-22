/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat [WSL: Ubuntu]
** File description:
** close_server
*/

#include "list.h"
#include "server.h"
#include "socket.h"
#include "utils.h"
#include "database.h"

void end_server(server_t *server)
{
    bool verif;

    while (server->clients != NULL)
        remove_last_client(&server->clients);
    verif = close_socket(server->sfd);
    if (!verif)
        error_exit(NULL);
    save_database_to_file(server->database);
    free_database(server->database);
    printf("Server stopped.\n");
}
