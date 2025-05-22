/*
** EPITECH PROJECT, 2024
** database
** File description:
** add_user
*/

#include "database.h"

void add_user(database_t *database, user_t user)
{
    database->users = realloc(database->users,
    sizeof(user_t) * (database->users_size + 2));
    database->users[database->users_size] = user;
    database->users_size++;
}

void set_user_status(database_t *database, const char *uuid,
    const char *status)
{
    int cmp;

    for (size_t i = 0; i < database->users_size; i++) {
        cmp = strcmp(database->users[i].USER_UUID, uuid);
        if (cmp == 0) {
            database->users[i].USER_STATUS = strdup(status);
            break;
        }
    }
}
