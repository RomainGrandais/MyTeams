/*
** EPITECH PROJECT, 2024
** database
** File description:
** get_user
*/

#include "database.h"

user_t get_user_by_uuid(database_t *database, char *uuid)
{
    user_t user = {0};

    for (unsigned int i = 0; i < database->users_size; i++) {
        if (strcmp((database->users[i].USER_UUID), uuid) == 0) {
            user = database->users[i];
            return user;
        }
    }
    return user;
}

user_t get_user_by_name(database_t *database, char *username)
{
    user_t user = {0};

    for (unsigned int i = 0; i < database->users_size; i++) {
        if (strcmp((database->users[i].USER_NAME), username) == 0) {
            user = database->users[i];
            return user;
        }
    }
    return user;
}
