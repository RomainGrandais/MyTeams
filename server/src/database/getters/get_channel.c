/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** get_channel
*/


#include "database.h"

channel_t get_channel_by_uuid(database_t *database, char *uuid)
{
    channel_t channel = {0};

    for (unsigned int i = 0; i < database->channels_size; i++) {
        if (strcmp((database->channels[i].CHANNEL_UUID), uuid) == 0) {
            channel = database->channels[i];
            return channel;
        }
    }
    return channel;
}
