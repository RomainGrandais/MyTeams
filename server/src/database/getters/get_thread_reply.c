/*
** EPITECH PROJECT, 2024
** database
** File description:
** get_thread_reply
*/

#include "database.h"

threads_reply_t get_thread_reply_by_uuid(database_t *database, char *uuid)
{
    threads_reply_t threadreply = {0};

    for (unsigned int i = 0; i < database->threads_size; i++) {
        if (strcmp((database->threads_reply[i].REPLY_UUID), uuid) == 0) {
            threadreply = database->threads_reply[i];
            return threadreply;
        }
    }
    return threadreply;
}

int get_thread_reply_size(database_t *database, char *uuid)
{
    int size = 0;

    for (unsigned int i = 0; i < database->threads_reply_size; i++) {
        if (strcmp((database->threads_reply[i].THREADS_UUID), uuid) == 0) {
            size++;
        }
    }
    return size;
}

char **get_theard_reply(database_t *database, char *thread_uuid)
{
    int size = get_thread_reply_size(database, thread_uuid);
    char **reply_uuids = malloc(sizeof(char *) * (size + 1));
    int index = 0;

    for (unsigned int i = 0; i < database->threads_reply_size; i++) {
        if (strcmp((database->threads_reply[i].THREADS_UUID),
            thread_uuid) == 0) {
            reply_uuids[index] = strdup(database->threads_reply[i].REPLY_UUID);
            index++;
        }
    }
    reply_uuids[index] = NULL;
    return reply_uuids;
}
