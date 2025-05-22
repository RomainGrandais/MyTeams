/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_team
*/

#include "database.h"

void add_team(database_t *database, team_t team)
{
    database->teams = realloc(database->teams,
    sizeof(team_t) * (database->teams_size + 2));
    database->teams[database->teams_size] = team;
    database->teams_size++;
}
