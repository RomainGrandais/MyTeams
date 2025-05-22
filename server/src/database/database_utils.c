/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** database_utils
*/

#include "database.h"

int get_index(char *line, int data_id)
{
    int index = 0;
    bool in_data = false;

    for (; data_id != 0; index++) {
        if (line[index] == '"')
            in_data = !in_data;
        if (line[index] == ',' && in_data == false)
            data_id--;
    }
    return index;
}

char *get_data(char *line, int data_id)
{
    char *data = malloc(sizeof(char) * (get_data_size(line, data_id) + 1));
    int index = get_index(line, data_id);
    int i = 0;

    for (; line[index] != '"'; index++);
    index += 1;
    for (; line[index] != '"'; i++) {
        data[i] = line[index];
        index++;
    }
    data[i] = '\0';
    return data;
}

int get_data_size(char *line, int data_id)
{
    int data_size = 0;
    int index = get_index(line, data_id);

    for (; line[index] != '"'; index++);
    for (index += 1; line[index] != '"'; data_size++)
        index++;
    return data_size;
}

database_t *init_database(void)
{
    database_t *database = malloc(sizeof(database_t));

    database->channels = malloc(sizeof(channel_t));
    database->messages = malloc(sizeof(message_t));
    database->teams_links = malloc(sizeof(teamLink_t));
    database->teams = malloc(sizeof(team_t));
    database->threads_reply = malloc(sizeof(threads_reply_t));
    database->threads = malloc(sizeof(thread_t));
    database->users = malloc(sizeof(user_t));
    database->channels_size = 0;
    database->messages_size = 0;
    database->teams_links_size = 0;
    database->teams_size = 0;
    database->threads_reply_size = 0;
    database->threads_size = 0;
    database->users_size = 0;
    return database;
}

int save_database_to_file(database_t *database)
{
    FILE *file = fopen("./storage/TeamsDatabase.db", "w");

    if (!file)
        return 84;
    save_teams(database, file);
    save_channels(database, file);
    save_threads(database, file);
    save_thread_reply(database, file);
    save_users(database, file);
    save_messages(database, file);
    save_team_links(database, file);
    fclose(file);
    return 0;
}
