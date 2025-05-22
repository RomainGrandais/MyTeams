/*
** EPITECH PROJECT, 2024
** database
** File description:
** get_message
*/

#include "database.h"

message_t get_message_by_uuid(database_t *database, char *uuid)
{
    message_t message = {0};

    for (unsigned int i = 0; i < database->messages_size; i++) {
        if (strcmp((database->messages[i].MESSAGE_UUID), uuid) == 0) {
            message = database->messages[i];
            return message;
        }
    }
    return message;
}

message_t get_message_by_sender_uuid(database_t *database, char *uuid)
{
    message_t message = {0};

    for (unsigned int i = 0; i < database->messages_size; i++) {
        if (strcmp((database->messages[i].SENDER_UUID), uuid) == 0) {
            message = database->messages[i];
            return message;
        }
    }
    return message;
}

message_t get_message_by_receiver_uuid(database_t *database, char *uuid)
{
    message_t message = {0};

    for (unsigned int i = 0; i < database->messages_size; i++) {
        if (strcmp((database->messages[i].RECEIVER_UUID), uuid) == 0) {
            message = database->messages[i];
            return message;
        }
    }
    return message;
}
