/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** client
*/

#include "client.h"
#include "commands.h"
#include "rfc.h"
#include "utils.h"

static void remove_newline(input_t *input)
{
    size_t len = input->read_size;

    if (len <= 1)
        return;
    if (input->buf[len - 1] == NEWLINE) {
        input->buf[len - 1] = NULL_BYTE;
        input->read_size -= 1;
        if (len >= 2 && input->buf[len - 2] == '\r') {
            input->buf[len - 2] = NULL_BYTE;
            input->read_size -= 1;
        }
    }
}

static bool get_input(int fd, input_t *input)
{
    input->buf = malloc(sizeof(char) * READ_BUFF_SIZE);
    if (input->buf == NULL)
        return false;
    memset(input->buf, 0, READ_BUFF_SIZE);
    input->read_size = read(fd, input->buf, READ_BUFF_SIZE);
    remove_newline(input);
    input->word_array = parse_command(input->buf);
    return true;
}

static bool find_command(input_t *input, server_t *server, client_t *client)
{
    int cmp;
    bool status;

    for (size_t i = 0; i < NB_CMD; i++) {
        cmp = strcmp(input->word_array->array[0], CMDS[i].name);
        if (cmp == 0) {
            status = CMDS[i].func(server, &client, input->word_array);
            return status;
        }
    }
    dprintf(client->fd, "%d\n", BAD_REQ);
    return true;
}

bool process_client(server_t *server, client_t *client)
{
    input_t input;
    bool verif;
    bool status;

    verif = get_input(client->fd, &input);
    if (!verif)
        return true;
    if (input.read_size == 0) {
        free(input.buf);
        return false;
    }
    status = find_command(&input, server, client);
    free(input.buf);
    free_warray(input.word_array);
    return status;
}
