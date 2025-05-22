/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"

int parse_line_team_link(database_t *database, char *line, int table_index)
{
    database->teams_links[table_index].TEAM_UUID = get_data(line, 0);
    database->teams_links[table_index].USER_UUID = get_data(line, 1);
    return 0;
}

int fill_team_link(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->teams_links_size = table_size;
    database->teams_links = realloc(database->teams_links,
    sizeof(teamLink_t) * (table_size + 1));
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_team_link(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
