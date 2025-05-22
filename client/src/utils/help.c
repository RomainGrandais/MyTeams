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
    printf("%s%s%s%s%s",
        USAGE_MSG, IP_MSG_LO, IP_MSG_LT, PORT_MSG_LO, PORT_MSG_LT);
    exit(0);
}

void get_help(const char *arg)
{
    bool verif = verify_help_arg(arg);

    if (!verif)
        error_exit("Invalid arguments. Run './myteams_server -h' for help.\n");
    display_help();
}
