/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** args
*/

#include "args.h"

bool verify_help_arg(const char *arg)
{
    int cmp = strcmp(arg, "-help");

    if (cmp != 0) {
        cmp = strcmp(arg, "-h");
        if (cmp != 0)
            return false;
    }
    return true;
}

bool get_port(const char *port_str, server_t *server)
{
    size_t port_len = strlen(port_str);

    for (size_t i = 0; i < port_len; i++) {
        if (port_str[i] < '0' || port_str[i] > '9') {
            printf("Invalid port: %s\n", port_str);
            return false;
        }
    }
    server->port = atoi(port_str);
    return true;
}
