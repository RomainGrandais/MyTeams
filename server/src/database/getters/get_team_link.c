/*
** EPITECH PROJECT, 2024
** database
** File description:
** get_team_link
*/

#include "database.h"

int get_subscribed_teams_uuids_size(database_t *database, char *uuid)
{
    int size = 0;

    for (unsigned int i = 0; i < database->teams_links_size; i++) {
        if (strcmp((database->teams_links[i].USER_UUID), uuid) == 0) {
            size++;
        }
    }
    return size;
}

int get_team_subscribers_uuids_size(database_t *database, char *uuid)
{
    int size = 0;

    for (unsigned int i = 0; i < database->teams_links_size; i++) {
        if (strcmp((database->teams_links[i].TEAM_UUID), uuid) == 0) {
            size++;
        }
    }
    return size;
}

char **get_subscribed_teams_uuids(database_t *database, char *uuid)
{
    int size = get_subscribed_teams_uuids_size(database, uuid);
    char **teams_uuids = malloc(sizeof(char *) * (size + 1));
    int index = 0;

    for (unsigned int i = 0; i < database->teams_links_size; i++) {
        if (strcmp((database->teams_links[i].USER_UUID), uuid) == 0) {
            teams_uuids[index] = strdup(database->teams_links[i].TEAM_UUID);
            index++;
        }
    }
    teams_uuids[index] = NULL;
    return teams_uuids;
}

char **get_team_subscribers_uuids(database_t *database, char *uuid)
{
    int size = get_team_subscribers_uuids_size(database, uuid);
    char **users_uuids = malloc(sizeof(char *) * (size + 1));
    int index = 0;

    for (unsigned int i = 0; i < database->teams_links_size; i++) {
        if (strcmp((database->teams_links[i].TEAM_UUID), uuid) == 0) {
            users_uuids[index] = strdup(database->teams_links[i].USER_UUID);
            index++;
        }
    }
    users_uuids[index] = NULL;
    return users_uuids;
}
