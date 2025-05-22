/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** send
*/

#include "commands.h"
#include "database.h"
#include "logging_server.h"
#include "rfc.h"
#include "utils.h"

static void remove_new_line(char **str)
{
    size_t len = strlen(*str);

    if (len < 1)
        return;
    if ((*str)[len - 1] == NEWLINE)
        (*str)[len - 1] = NULL_BYTE;
}

static void create_message(server_t *server, client_t **client,
    warray_t *word_array, message_t *message)
{
    time_t curr;
    struct tm *local;
    char *str_time;

    time(&curr);
    local = localtime(&curr);
    str_time = asctime(local);
    remove_new_line(&str_time);
    message->SENDER_UUID = (*client)->user.USER_UUID;
    message->RECEIVER_UUID = strdup(word_array->array[1]);
    message->MESSAGE_BODY = strdup(word_array->array[2]);
    message->MESSAGE_UUID = create_uuid();
    message->TIMESTAMP = strdup(str_time);
    add_message(server->database, *message);
    save_database_to_file(server->database);
    server_event_private_message_sended(message->SENDER_UUID,
        message->RECEIVER_UUID, message->MESSAGE_BODY);
}

bool send_msg(server_t *server, client_t **client, warray_t *word_array)
{
    message_t message;
    user_t receiver;

    if (word_array->size != 3) {
        dprintf((*client)->fd, "%d\n", BAD_SYNTAX);
        return true;
    }
    if (!(*client)->logged_in) {
        dprintf((*client)->fd, "%d\n", NOT_CON);
        return true;
    }
    receiver = get_user_by_uuid(server->database, word_array->array[1]);
    if (receiver.USER_NAME == NULL) {
        dprintf((*client)->fd, "%d\n", NO_USR);
        return true;
    }
    create_message(server, client, word_array, &message);
    dprintf((*client)->fd, "%d \"%s\" \"%s\"\n", MSG_SEND,
        message.SENDER_UUID, message.MESSAGE_BODY);
    return true;
}
