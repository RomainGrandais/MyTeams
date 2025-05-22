/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"

int parse_line_thread(database_t *database, char *line, int table_index)
{
    database->threads[table_index].THREAD_NAME = get_data(line, 0);
    database->threads[table_index].THREAD_UUID = get_data(line, 1);
    database->threads[table_index].CHANNEL_UUID = get_data(line, 2);
    return 0;
}

int fill_thread(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->threads_size = table_size;
    database->threads = realloc(database->threads,
    (sizeof(thread_t) * (table_size + 1)));
    database->threads[table_size].THREAD_NAME = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_thread(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
