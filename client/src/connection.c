/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** connection
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include "args.h"
#include "utils.h"
#include "structures.h"

int connect_to_server(client_t *client)
{
    struct sockaddr_in server_addr;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        printf("Error creating socket");
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->con_port);
    server_addr.sin_addr.s_addr = client->con_ip;
    if (connect(client->sockfd, (struct sockaddr *)&server_addr,
        sizeof(server_addr)) < 0) {
        printf("Error connecting to server");
        close(client->sockfd);
        return -1;
    }
    return client->sockfd;
}
