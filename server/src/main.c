/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** main
*/

#include "args.h"
#include "server.h"
#include "socket.h"
#include "utils.h"

int main(int ac, char **av)
{
    server_t server;
    bool verif;

    if (ac != 2)
        error_exit("Invalid arguments. Run './myteams_server -h' for help.\n");
    get_help(av[1]);
    verif = get_port(av[1], &server);
    if (!verif)
        return 84;
    server.sfd = create_socket(server.port);
    if (server.sfd == -1)
        return 84;
    run_server(&server);
    end_server(&server);
    return 0;
}
