/*
** EPITECH PROJECT, 2024
** database
** File description:
** get_team
*/

#include "database.h"

team_t get_team_by_uuid(database_t *database, char *uuid)
{
    team_t team = {0};

    for (unsigned int i = 0; i < database->teams_size; i++) {
        if (strcmp((database->teams[i].TEAM_UUID), uuid) == 0) {
            team = database->teams[i];
            return team;
        }
    }
    return team;
}
