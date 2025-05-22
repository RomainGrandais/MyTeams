/*
** EPITECH PROJECT, 2024
** database
** File description:
** get_thread
*/

#include "database.h"

thread_t get_thread_by_uuid(database_t *database, char *uuid)
{
    thread_t thread = {0};

    for (unsigned int i = 0; i < database->threads_size; i++) {
        if (strcmp((database->threads[i].THREAD_UUID), uuid) == 0) {
            thread = database->threads[i];
            return thread;
        }
    }
    return thread;
}
