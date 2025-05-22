/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat [WSL: Ubuntu]
** File description:
** login
*/

#include "commands.h"
#include "database.h"
#include "logging_server.h"
#include "rfc.h"
#include "utils.h"

static void create_user(server_t *server, client_t **client,
    warray_t *word_array)
{
    (*client)->user.USER_NAME = strdup(word_array->array[1]);
    (*client)->user.USER_UUID = create_uuid();
    (*client)->user.USER_STATUS = "1";
    add_user(server->database, (*client)->user);
    save_database_to_file(server->database);
    server_event_user_created((*client)->user.USER_UUID,
        (*client)->user.USER_NAME);
}

bool login(server_t *server, client_t **client, warray_t *word_array)
{
    if ((*client)->logged_in) {
        dprintf((*client)->fd, "%d\n", ALREADY_LOG);
        return true;
    }
    if (word_array->size != 2) {
        dprintf((*client)->fd, "%d\n", BAD_SYNTAX);
        return true;
    }
    (*client)->user = get_user_by_name(server->database, word_array->array[1]);
    if ((*client)->user.USER_NAME == NULL) {
        create_user(server, client, word_array);
    } else {
        set_user_status(server->database, (*client)->user.USER_UUID, "1");
    }
    dprintf((*client)->fd, "%d \"%s\" \"%s\"\n", LOGIN,
        (*client)->user.USER_UUID, (*client)->user.USER_NAME);
    server_event_user_logged_in((*client)->user.USER_UUID);
    (*client)->logged_in = true;
    return true;
}
