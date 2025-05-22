/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat [WSL: Ubuntu]
** File description:
** help
*/

#include "commands.h"
#include "rfc.h"

static void prepare_tmp_str(char **tmp, size_t *tmp_len,
    size_t help_len, size_t i)
{
    *tmp_len = help_len + strlen(CMDS[i].help_one)
        + strlen(CMDS[i].help_two) + 1;
    *tmp = malloc(sizeof(char) * (*tmp_len + 1));
    memset(*tmp, 0, *tmp_len + 1);
}

static void send_help(client_t **client)
{
    char *help_str = NULL;
    char *tmp = NULL;
    size_t help_len = 0;
    size_t tmp_len = 0;

    for (size_t i = 0; i < NB_CMD; i++) {
        prepare_tmp_str(&tmp, &tmp_len, help_len, i);
        if (help_str != NULL) {
            strcat(tmp, help_str);
            free(help_str);
        }
        strcat(tmp, CMDS[i].help_one);
        strcat(tmp, CMDS[i].help_two);
        tmp[tmp_len - 1] = NEWLINE;
        help_str = tmp;
        help_len = tmp_len;
    }
    dprintf((*client)->fd, "%d %s\n", INFO, help_str);
    free(help_str);
}

bool help(server_t *server, client_t **client, warray_t *word_array)
{
    (void) server;
    if (word_array->size != 1) {
        dprintf((*client)->fd, "%d\n", BAD_SYNTAX);
        return true;
    }
    send_help(client);
    return true;
}
