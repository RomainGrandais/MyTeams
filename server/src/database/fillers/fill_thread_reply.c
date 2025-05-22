/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"

int parse_line_thread_reply(database_t *database, char *line, int table_index)
{
    database->threads_reply[table_index].REPLY_BODY = get_data(line, 0);
    database->threads_reply[table_index].REPLY_UUID = get_data(line, 1);
    database->threads_reply[table_index].TIMESTAMP = get_data(line, 2);
    database->threads_reply[table_index].SENDER_UUID = get_data(line, 3);
    database->threads_reply[table_index].THREADS_UUID = get_data(line, 4);
    return 0;
}

int fill_thread_reply(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->threads_reply_size = table_size;
    database->threads_reply = realloc(database->threads_reply,
    (sizeof(threads_reply_t) * (table_size + 1)));
    database->threads_reply[table_size].REPLY_BODY = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_thread_reply(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
