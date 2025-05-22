/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** commands_gestion
*/

#include "structures.h"
#include "commons.h"

void send_command(int sockfd, char *command)
{
    if (command != NULL) {
        send(sockfd, command, strlen(command), 0);
    }
}

void receive_response(int sockfd)
{
    char buffer[1024];
    int num_bytes;
    char **command;

    num_bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (num_bytes > 0) {
        buffer[num_bytes] = '\0';
        command = parse_command(buffer);
        handle_response(command);
    } else if (num_bytes == 0) {
        printf("Connection closed by server\n");
        exit(0);
    } else {
        printf("recv failed");
    }
}

void handle_user_input(int sockfd)
{
    char input[1024];

    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;
        send_command(sockfd, input);
    } else {
        error_exit("Input error or end of file encountered.\n");
    }
}

void handle_server_response(int sockfd)
{
    receive_response(sockfd);
}

void main_loop(int sockfd)
{
    fd_set read_fds;
    int max_fd = sockfd;

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(sockfd, &read_fds);
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            error_exit("select failed\n");
        }
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            handle_user_input(sockfd);
        }
        if (FD_ISSET(sockfd, &read_fds)) {
            handle_server_response(sockfd);
        }
    }
}
