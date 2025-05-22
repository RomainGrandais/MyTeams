/*
** EPITECH PROJECT, 2024
** database
** File description:
** fill_database
*/

#include "database.h"

int parse_line_thread_msg(database_t *database, char *line, int table_index)
{
    database->messages[table_index].MESSAGE_BODY = get_data(line, 0);
    database->messages[table_index].MESSAGE_UUID = get_data(line, 1);
    database->messages[table_index].TIMESTAMP = get_data(line, 2);
    database->messages[table_index].SENDER_UUID = get_data(line, 3);
    database->messages[table_index].RECEIVER_UUID = get_data(line, 4);
    return 0;
}

int fill_message(database_t *database, FILE *file)
{
    char line[256];
    int table_size = 0;
    int table_index = 0;

    fgets(line, sizeof(line), file);
    table_size = atoi(line);
    database->messages_size = table_size;
    database->messages = realloc(database->messages,
    (sizeof(message_t) * (table_size + 1)));
    database->messages[table_size].MESSAGE_BODY = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0)
            break;
        if (line[0] == '{') {
            parse_line_thread_msg(database, line, table_index);
            table_index++;
        }
    }
    return 0;
}
