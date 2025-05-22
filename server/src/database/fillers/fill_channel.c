/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"

int parse_line_channel(database_t *database, char *line, int table_index)
{
    database->channels[table_index].CHANNEL_NAME = get_data(line, 0);
    database->channels[table_index].CHANNEL_UUID = get_data(line, 1);
    database->channels[table_index].TEAM_UUID = get_data(line, 2);
    return 0;
}

int fill_channel(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->channels_size = table_size;
    database->channels = realloc(database->channels,
    (sizeof(channel_t) * (table_size + 1)));
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_channel(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
