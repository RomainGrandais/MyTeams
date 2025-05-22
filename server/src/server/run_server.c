/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** server
*/

#include "connection.h"
#include "database.h"
#include "server.h"

static bool is_server_running(int serv_state)
{
    static bool run;

    if (serv_state != -1)
        run = (bool) serv_state;
    return run;
}

static void signal_exit(UNUSED int signal)
{
    printf("Request to stop server.\n");
    is_server_running(0);
}

static void init_server(server_t *server)
{
    server->database = init_database();
    open_database(server->database);
    listen_con(server->sfd);
    FD_ZERO(&server->all_fds);
    FD_SET(server->sfd, &server->all_fds);
    server->n_fds = server->sfd + 1;
}

static void reset_fds(server_t *server)
{
    server->max_fd = 0;
    for (int fd = LOWEST_FD; fd < server->n_fds; fd++) {
        if (FD_ISSET(fd, &server->all_fds) != 0 && fd > server->max_fd)
            server->max_fd = fd;
    }
    server->n_fds = server->max_fd + 1;
    server->read_fds = server->all_fds;
}

void run_server(server_t *server)
{
    int err;

    server->clients = NULL;
    server->state = is_server_running(1);
    signal(SIGINT, signal_exit);
    init_server(server);
    while (server->state) {
        reset_fds(server);
        err = select(server->n_fds, &server->read_fds, NULL, NULL, NULL);
        if (err == -1)
            return;
        process_connections(server);
        server->state = is_server_running(-1);
    }
}
