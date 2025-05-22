/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat [WSL: Ubuntu]
** File description:
** logout
*/

#include "commands.h"
#include "database.h"
#include "rfc.h"

bool logout(server_t *server, client_t **client, warray_t *word_array)
{
    (void) server;
    if (word_array->size != 1) {
        dprintf((*client)->fd, "%d\n", BAD_SYNTAX);
        return true;
    }
    if ((*client)->logged_in) {
        dprintf((*client)->fd, "%d \"%s\" \"%s\"\n", LOGOUT,
            (*client)->user.USER_UUID, (*client)->user.USER_NAME);
        set_user_status(server->database, (*client)->user.USER_UUID, "0");
        save_database_to_file(server->database);
    } else {
        dprintf((*client)->fd, "%d\n", CON_CLOSE);
    }
    return false;
}
