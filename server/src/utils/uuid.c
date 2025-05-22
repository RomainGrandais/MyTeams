/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** uuid
*/

#include "utils.h"

char *create_uuid(void)
{
    uuid_t new_uuid;
    char *uuid = malloc(sizeof(char) * (UUID_SIZE + 1));

    uuid_generate(new_uuid);
    uuid_unparse(new_uuid, uuid);
    return uuid;
}
