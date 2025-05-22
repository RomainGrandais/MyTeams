/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_message
*/

#include "database.h"

void add_message(database_t *database, message_t message)
{
    database->messages = realloc(database->messages,
    sizeof(message_t) * (database->messages_size + 2));
    database->messages[database->messages_size] = message;
    database->messages_size++;
}
