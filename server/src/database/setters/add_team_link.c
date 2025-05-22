/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_team_lin
*/

#include "database.h"

void add_team_link(database_t *database, teamLink_t team_link)
{
    database->teams_links = realloc(database->teams_links,
    sizeof(teamLink_t) * (database->teams_links_size + 2));
    database->teams_links[database->teams_links_size] = team_link;
    database->teams_links_size++;
}
