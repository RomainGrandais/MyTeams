/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"
#include "logging_server.h"

int parse_line_user(database_t *database, char *line, int table_index)
{
    database->users[table_index].USER_NAME = get_data(line, 0);
    database->users[table_index].USER_UUID = get_data(line, 1);
    database->users[table_index].USER_STATUS = get_data(line, 2);
    server_event_user_loaded(database->users[table_index].USER_UUID,
        database->users[table_index].USER_NAME);
    return 0;
}

int fill_user(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->users_size = table_size;
    database->users = realloc(database->users,
    (sizeof(user_t) * (table_size + 1)));
    database->users[table_size].USER_NAME = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_user(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
