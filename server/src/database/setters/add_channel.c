/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_channel
*/

#include "database.h"

void add_channel(database_t *database, channel_t channel)
{
    database->channels = realloc(database->channels,
    sizeof(channel_t) * (database->channels_size + 2));
    database->channels[database->channels_size] = channel;
    database->channels_size++;
}
