/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_thread_reply
*/

#include "database.h"

void add_thread_reply(database_t *database, threads_reply_t thread_reply)
{
    database->threads_reply = realloc(database->threads_reply,
    sizeof(threads_reply_t) * (database->threads_reply_size + 2));
    database->threads_reply[database->threads_reply_size] = thread_reply;
    database->threads_reply_size++;
}
