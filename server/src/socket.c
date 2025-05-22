/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** socket
*/

#include "socket.h"

bool close_socket(int sfd)
{
    int err;

    err = close(sfd);
    if (err == -1) {
        printf("Failed to properly close socket. File descriptor: %d\n", sfd);
        return false;
    }
    return true;
}

bool reset_socket(int sfd)
{
    int optval = 1;
    int sock_err;

    sock_err = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int));
    if (sock_err == -1) {
        printf("Failed to properly reset socket. File descriptor: %d\n", sfd);
        return false;
    }
    return true;
}

static bool bind_socket(int sfd, int port)
{
    struct sockaddr_in s_address;
    int err;

    memset(&s_address, 0, sizeof(s_address));
    s_address.sin_family = AF_INET;
    s_address.sin_port = htons(port);
    s_address.sin_addr.s_addr = INADDR_ANY;
    err = bind(sfd, (struct sockaddr *)&s_address, sizeof(s_address));
    if (err == -1)
        return false;
    return true;
}

int create_socket(int port)
{
    int sfd;
    bool sock_err;
    bool bind_err;

    sfd = socket(AF_INET, SOCK_STREAM, 6);
    if (sfd == -1) {
        printf("Failed to create socket.\n");
        return sfd;
    }
    sock_err = reset_socket(sfd);
    bind_err = bind_socket(sfd, port);
    if (!sock_err || !bind_err) {
        close_socket(sfd);
        printf("Failed to bind socket.\n");
        return -1;
    }
    return sfd;
}
