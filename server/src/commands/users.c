/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** users
*/

#include "commands.h"
#include "rfc.h"
#include "utils.h"

static char *concat_users(char *dest, char *user)
{
    size_t len = strlen(user) + 1;
    char *str;

    if (dest != NULL)
        len += strlen(dest);
    str = malloc(sizeof(char) * (len + 1));
    memset(str, 0, len + 1);
    if (dest != NULL) {
        strcat(str, dest);
        strcat(str, " ");
    }
    strcat(str, user);
    if (dest != NULL)
        free(dest);
    free(user);
    return str;
}

static void print_result(char *users_str, client_t **client)
{
    if (strlen(users_str) == 0) {
        dprintf((*client)->fd, "%d\n", NO_USR);
    } else {
        dprintf((*client)->fd, "%d %s\n", USR_LIST, users_str);
        free(users_str);
    }
}

bool users(server_t *server, client_t **client, warray_t *word_array)
{
    char *users_str = NULL;
    char *user = NULL;

    if (word_array->size != 1) {
        dprintf((*client)->fd, "%d\n", BAD_SYNTAX);
        return true;
    }
    if (!(*client)->logged_in) {
        dprintf((*client)->fd, "%d\n", NOT_CON);
        return true;
    }
    for (size_t i = 0; i < server->database->users_size; i++) {
        user = stringify_user(&server->database->users[i]);
        users_str = concat_users(users_str, user);
    }
    print_result(users_str, client);
    return true;
}
