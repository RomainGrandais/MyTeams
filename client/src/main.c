/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** main
*/

#include "args.h"
#include "utils.h"
#include "structures.h"

int main(int ac, char **av)
{
    client_t client;
    int sockfd;

    if (ac != 3) {
        error_exit("Invalid arguments. Usage: ./myteams_cli ip port\n");
        return 84;
    }
    client.con_port = atoi(av[2]);
    client.con_ip = inet_addr(av[1]);
    sockfd = connect_to_server(&client);
    if (sockfd < 0) {
        return 84;
    }
    main_loop(sockfd);
    close(sockfd);
    return 0;
}
