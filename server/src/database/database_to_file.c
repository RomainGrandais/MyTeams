/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** database_to_file
*/

#include "database.h"

void save_channels(database_t *database, FILE *file)
{
    fprintf(file, "[CHANNELS]\n");
    if (database->channels_size == 0) {
        fprintf(file, "%d\n\n", database->channels_size);
    } else {
        fprintf(file, "%d\n", database->channels_size);
        for (unsigned int i = 0; i < database->channels_size; i++)
            fprintf(file, "{\"%s\",\"%s\",\"%s\"}\n",
            database->channels[i].CHANNEL_NAME,
            database->channels[i].CHANNEL_UUID,
            database->channels[i].TEAM_UUID);
        fprintf(file, "\n");
    }
}

void save_messages(database_t *database, FILE *file)
{
    fprintf(file, "[MESSAGES]\n");
    if (database->messages_size == 0) {
        fprintf(file, "%d\n\n", database->messages_size);
    } else {
        fprintf(file, "%d\n", database->messages_size);
        for (unsigned int i = 0; i < database->messages_size; i++)
            fprintf(file, "{\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"}\n",
            database->messages[i].MESSAGE_BODY,
            database->messages[i].MESSAGE_UUID,
            database->messages[i].TIMESTAMP,
            database->messages[i].SENDER_UUID,
            database->messages[i].RECEIVER_UUID);
        fprintf(file, "\n");
    }
}

void save_team_links(database_t *database, FILE *file)
{
    fprintf(file, "[TEAMS_LINK]\n");
    if (database->teams_links_size == 0) {
        fprintf(file, "%d\n\n", database->teams_links_size);
    } else {
        fprintf(file, "%d\n", database->teams_links_size);
        for (unsigned int i = 0; i < database->teams_links_size; i++)
            fprintf(file, "{\"%s\",\"%s\"}\n",
            database->teams_links[i].TEAM_UUID,
            database->teams_links[i].USER_UUID);
        fprintf(file, "\n");
    }
}

void save_teams(database_t *database, FILE *file)
{
    fprintf(file, "[TEAMS]\n");
    if (database->teams_size == 0) {
        fprintf(file, "%d\n\n", database->teams_size);
    } else {
        fprintf(file, "%d\n", database->teams_size);
        for (unsigned int i = 0; i < database->teams_size; i++)
            fprintf(file, "{\"%s\",\"%s\"}\n",
            database->teams[i].TEAM_NAME,
            database->teams[i].TEAM_UUID);
        fprintf(file, "\n");
    }
}
