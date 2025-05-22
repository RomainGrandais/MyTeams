/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"

int parse_line_teams(database_t *database, char *line, int table_index)
{
    database->teams[table_index].TEAM_NAME = get_data(line, 0);
    database->teams[table_index].TEAM_UUID = get_data(line, 1);
    return 0;
}

int fill_team(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->teams_size = table_size;
    database->teams = realloc(database->teams,
    sizeof(team_t) * (table_size + 1));
    database->teams[table_size].TEAM_NAME = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_teams(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
