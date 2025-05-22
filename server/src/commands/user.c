/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** user
*/

#include "commands.h"
#include "database.h"
#include "rfc.h"
#include "utils.h"

bool user(server_t *server, client_t **client, warray_t *word_array)
{
    char *user_str = NULL;
    user_t user;

    if (word_array->size != 2) {
        dprintf((*client)->fd, "%d\n", BAD_SYNTAX);
        return true;
    }
    if (!(*client)->logged_in) {
        dprintf((*client)->fd, "%d\n", NOT_CON);
        return true;
    }
    user = get_user_by_uuid(server->database, word_array->array[1]);
    if (user.USER_NAME != NULL) {
        user_str = stringify_user(&user);
        dprintf((*client)->fd, "%d %s\n", USR_EXIST, user_str);
    } else {
        dprintf((*client)->fd, "%d\n", NO_USR);
    }
    return true;
}
