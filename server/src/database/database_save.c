/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** database_save
*/

#include "database.h"

void save_thread_reply(database_t *database, FILE *file)
{
    fprintf(file, "[THREADS_REPLY]\n");
    if (database->threads_reply_size == 0) {
        fprintf(file, "%d\n\n", database->threads_reply_size);
    } else {
        fprintf(file, "%d\n", database->threads_reply_size);
        for (unsigned int i = 0; i < database->threads_reply_size; i++)
            fprintf(file, "{\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"}\n",
            database->threads_reply[i].REPLY_BODY,
            database->threads_reply[i].REPLY_UUID,
            database->threads_reply[i].TIMESTAMP,
            database->threads_reply[i].SENDER_UUID,
            database->threads_reply[i].THREADS_UUID);
        fprintf(file, "\n");
    }
}

void save_threads(database_t *database, FILE *file)
{
    fprintf(file, "[THREADS]\n");
    if (database->threads_size == 0) {
        fprintf(file, "%d\n\n", database->threads_size);
    } else {
        fprintf(file, "%d\n", database->threads_size);
        for (unsigned int i = 0; i < database->threads_size; i++)
            fprintf(file, "{\"%s\",\"%s\",\"%s\"}\n",
            database->threads[i].THREAD_NAME,
            database->threads[i].THREAD_UUID,
            database->threads[i].CHANNEL_UUID);
        fprintf(file, "\n");
    }
}

void save_users(database_t *database, FILE *file)
{
    fprintf(file, "[USERS]\n");
    if (database->users_size == 0) {
        fprintf(file, "%d\n\n", database->users_size);
    } else {
        fprintf(file, "%d\n", database->users_size);
        for (unsigned int i = 0; i < database->users_size; i++)
            fprintf(file, "{\"%s\",\"%s\",\"%s\"}\n",
            database->users[i].USER_NAME,
            database->users[i].USER_UUID,
            database->users[i].USER_STATUS);
        fprintf(file, "\n");
    }
}
