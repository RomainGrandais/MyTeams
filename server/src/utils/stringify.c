/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** stringify
*/

#include "utils.h"

char *stringify_user(user_t *user)
{
    size_t len = strlen(user->USER_NAME) + strlen(user->USER_UUID)
        + strlen(user->USER_STATUS) + 8;
    char *str = malloc(sizeof(char) * (len + 1));

    memset(str, 0, len + 1);
    strcat(str, "\"");
    strcat(str, user->USER_UUID);
    strcat(str, "\" \"");
    strcat(str, user->USER_NAME);
    strcat(str, "\" \"");
    strcat(str, user->USER_STATUS);
    strcat(str, "\"");
    return str;
}

char *stringify_message(message_t *message)
{
    size_t len = strlen(message->MESSAGE_BODY) + strlen(message->MESSAGE_UUID)
        + strlen(message->RECEIVER_UUID) + strlen(message->SENDER_UUID)
        + strlen(message->TIMESTAMP) + 14;
    char *str = malloc(sizeof(char) * (len + 1));

    memset(str, 0, len + 1);
    strcat(str, "\"");
    strcat(str, message->MESSAGE_UUID);
    strcat(str, "\" \"");
    strcat(str, message->MESSAGE_BODY);
    strcat(str, "\" \"");
    strcat(str, message->TIMESTAMP);
    strcat(str, "\" \"");
    strcat(str, message->SENDER_UUID);
    strcat(str, "\" \"");
    strcat(str, message->RECEIVER_UUID);
    strcat(str, "\"");
    return str;
}
