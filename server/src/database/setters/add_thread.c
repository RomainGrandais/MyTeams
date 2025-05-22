/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_thread
*/

#include "database.h"

void add_thread(database_t *database, thread_t thread)
{
    database->threads = realloc(database->threads,
    sizeof(thread_t) * (database->threads_size + 2));
    database->threads[database->threads_size] = thread;
    database->threads_size++;
}
