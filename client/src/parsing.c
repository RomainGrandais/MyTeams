/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** parsing
*/

#include "structures.h"

static const char *parse_argument_value(const char *input, char **arg,
    const char *start, int in_quotes)
{
    while (*input && ((in_quotes && *input != '\"') ||
        (!in_quotes && *input != ' '))) {
        input++;
    }
    if (in_quotes && *input == '\"') {
        in_quotes = 0;
    } else if (in_quotes && !*input) {
        fprintf(stderr, "Error: missing closing quote\n");
        error_exit("Error: missing closing quote\n");
    }
    *arg = malloc(input - start + 1);
    if (!*arg) {
        error_exit("Failed to allocate memory for an argument");
    }
    strncpy(*arg, start, input - start);
    (*arg)[input - start] = '\0';
    return input;
}

static const char *parse_argument(const char *input, char **arg)
{
    const char *start;
    int in_quotes = 0;

    while (*input == ' ')
        input++;
    if (*input == '\"') {
        ++input;
        start = input;
        in_quotes = 1;
    } else {
        start = input;
        in_quotes = 0;
    }
    input = parse_argument_value(input, arg, start, in_quotes);
    return input;
}

char **parse_command(const char *input)
{
    char **argv = calloc(MAX_ARGS, sizeof(char *));
    int argc = 0;
    char *arg;

    if (!argv) {
        error_exit("Failed to allocate argv array");
    }
    while (*input) {
        input = parse_argument(input, &arg);
        argv[argc] = arg;
        argc++;
        if (*input)
            input++;
    }
    argv[argc] = NULL;
    return argv;
}
