/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** free_database
*/

#include "database.h"

void free_user_content(database_t *database)
{
    for (unsigned int i = 0; i < database->messages_size; i++) {
        free(database->messages[i].MESSAGE_BODY);
        free(database->messages[i].MESSAGE_UUID);
        free(database->messages[i].TIMESTAMP);
        free(database->messages[i].SENDER_UUID);
        free(database->messages[i].RECEIVER_UUID);
    }
    for (unsigned int i = 0; i < database->users_size; i++) {
        free(database->users[i].USER_NAME);
        free(database->users[i].USER_UUID);
        free(database->users[i].USER_STATUS);
    }
}

void free_team_content(database_t *database)
{
    for (unsigned int i = 0; i < database->teams_links_size; i++) {
        free(database->teams_links[i].TEAM_UUID);
        free(database->teams_links[i].USER_UUID);
    }
    for (unsigned int i = 0; i < database->teams_size; i++) {
        free(database->teams[i].TEAM_NAME);
        free(database->teams[i].TEAM_UUID);
    }
}

void free_thread_content(database_t *database)
{
    for (unsigned int i = 0; i < database->threads_reply_size; i++) {
        free(database->threads_reply[i].REPLY_BODY);
        free(database->threads_reply[i].REPLY_UUID);
        free(database->threads_reply[i].TIMESTAMP);
        free(database->threads_reply[i].SENDER_UUID);
        free(database->threads_reply[i].THREADS_UUID);
    }
    for (unsigned int i = 0; i < database->threads_size; i++) {
        free(database->threads[i].THREAD_NAME);
        free(database->threads[i].THREAD_UUID);
        free(database->threads[i].CHANNEL_UUID);
    }
}

void free_database(database_t *database)
{
    for (unsigned int i = 0; i < database->channels_size; i++) {
        free(database->channels[i].CHANNEL_NAME);
        free(database->channels[i].CHANNEL_UUID);
        free(database->channels[i].TEAM_UUID);
    }
    free_team_content(database);
    free_thread_content(database);
    free_user_content(database);
    free(database->channels);
    free(database->messages);
    free(database->teams_links);
    free(database->teams);
    free(database->threads_reply);
    free(database->threads);
    free(database->users);
    free(database);
}
