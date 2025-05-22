/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** connection
*/

#include "client.h"
#include "connection.h"
#include "rfc.h"
#include "list.h"
#include "server.h"
#include "socket.h"
#include "utils.h"

void listen_con(int sfd)
{
    int err = listen(sfd, MAX_LEN_QUEUE);

    if (err == -1) {
        close_socket(sfd);
        error_exit("Error listening to socket.\n");
    }
}

int accept_con(int sfd)
{
    int cfd;
    struct sockaddr_in c_addr;
    socklen_t c_len = sizeof(c_addr);
    char *ip;
    int port;

    cfd = accept(sfd, (struct sockaddr *)&c_addr,
        (socklen_t *__restrict__)&c_len);
    if (cfd == -1) {
        printf("Failed to accept incoming connection.\n");
        return cfd;
    }
    ip = inet_ntoa(c_addr.sin_addr);
    port = ntohs(c_addr.sin_port);
    printf("Connection from %s:%d opened on fd: %d\n", ip, port, cfd);
    dprintf(cfd, "%d\n", CON_ESTABLISHED);
    return cfd;
}

static void check_fd(server_t *server, int fd)
{
    bool is_open;
    client_t *it = server->clients;

    while (it->next != NULL && it->fd != fd)
        it = it->next;
    is_open = process_client(server, it);
    if (!is_open) {
        FD_CLR(fd, &server->all_fds);
        reset_socket(fd);
        close_socket(fd);
        remove_client(&server->clients, fd);
        printf("Close connection on fd: %d\n", fd);
    }
}

void process_connections(server_t *server)
{
    int cfd;
    int fd_exist;

    for (int fd = LOWEST_FD; fd < server->n_fds; fd++) {
        fd_exist = FD_ISSET(fd, &server->read_fds);
        if (fd_exist == 0)
            continue;
        if (fd != server->sfd) {
            check_fd(server, fd);
            continue;
        }
        cfd = accept_con(server->sfd);
        if (cfd == -1)
            continue;
        add_client(&server->clients, cfd);
        FD_SET(cfd, &server->all_fds);
        server->n_fds = cfd + 1;
    }
}
