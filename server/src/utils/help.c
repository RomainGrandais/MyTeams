/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune [WSL: Ubuntu]
** File description:
** help
*/

#include "args.h"
#include "utils.h"

void display_help(void)
{
    printf("%s%s%s", USAGE_MSG, PORT_MSG_LO, PORT_MSG_LT);
    exit(0);
}

void get_help(const char *arg)
{
    bool verif = verify_help_arg(arg);

    if (!verif)
        return;
    display_help();
}
