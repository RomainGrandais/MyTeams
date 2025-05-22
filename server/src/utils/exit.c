/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** exit
*/

#include "utils.h"

void error_exit(const char *msg)
{
    size_t msg_len;

    if (msg != NULL) {
        msg_len = strlen(msg);
        if (msg_len != 0)
            printf("%s", msg);
    }
    exit(84);
}
