/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** messages
*/

#include "commands.h"
#include "database.h"
#include "rfc.h"
#include "utils.h"

static char *concat_messages(char *dest, char *msg)
{
    size_t len = strlen(msg) + 1;
    char *str;

    if (dest != NULL)
        len += strlen(dest);
    str = malloc(sizeof(char) * (len + 1));
    memset(str, 0, len + 1);
    if (dest != NULL) {
        strcat(str, dest);
        strcat(str, " ");
        free(dest);
    }
    strcat(str, msg);
    free(msg);
    return str;
}

static char *get_messages(database_t *database, client_t **client,
    warray_t *word_array)
{
    char *messages_str = NULL;
    char *msg = NULL;

    for (size_t i = 0; i < database->messages_size; i++) {
        if (strcmp(database->messages[i].SENDER_UUID,
            (*client)->user.USER_UUID) != 0
            || strcmp(database->messages[i].SENDER_UUID,
            word_array->array[1]) != 0)
            continue;
        if (strcmp(database->messages[i].RECEIVER_UUID,
            (*client)->user.USER_UUID) != 0
            || strcmp(database->messages[i].RECEIVER_UUID,
            word_array->array[1]) != 0)
            continue;
        msg = stringify_message(&database->messages[i]);
        messages_str = concat_messages(messages_str, msg);
    }
    return messages_str;
}

static void send_result(client_t **client, char *str)
{
    if (str == NULL) {
        dprintf((*client)->fd, "%d\n", NO_MSG);
    } else {
        dprintf((*client)->fd, "%d %s\n", MSG_EXIST, str);
        free(str);
    }
}

bool messages(server_t *server, client_t **client, warray_t *word_array)
{
    char *str;
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
    if (user.USER_NAME == NULL) {
        dprintf((*client)->fd, "%d\n", NO_USR);
        return true;
    }
    str = get_messages(server->database, client, word_array);
    send_result(client, str);
    return true;
}
