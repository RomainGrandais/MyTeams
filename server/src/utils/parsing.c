/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat
** File description:
** parsing
*/

#include "utils.h"

static const char *parse_argument_value(const char *str, char **arg,
    const char *start, int in_quotes)
{
    while (*str && ((in_quotes && *str != '\"') ||
        (!in_quotes && *str != ' '))) {
        str++;
    }
    if (in_quotes && *str == '\"') {
        in_quotes = 0;
    } else if (in_quotes && !*str) {
        *arg = NULL;
        return str;
    }
    *arg = malloc(str - start + 1);
    if (!*arg) {
        *arg = NULL;
        return str;
    }
    strncpy(*arg, start, str - start);
    (*arg)[str - start] = NULL_BYTE;
    return str;
}

static const char *parse_argument(const char *str, char **arg)
{
    const char *start;
    int in_quotes = 0;

    while (*str == ' ')
        str++;
    if (*str == '\"') {
        ++str;
        start = str;
        in_quotes = 1;
    } else {
        start = str;
        in_quotes = 0;
    }
    str = parse_argument_value(str, arg, start, in_quotes);
    return str;
}

warray_t *parse_command(const char *str)
{
    warray_t *warray = malloc(sizeof(warray_t));
    char *arg;

    warray->size = 0;
    warray->array = calloc(MAX_ARGS, sizeof(char *));
    if (warray->array == NULL)
        return NULL;
    while (*str) {
        str = parse_argument(str, &arg);
        if (arg == NULL) {
            free_warray(warray);
            return NULL;
        }
        warray->array[warray->size] = arg;
        warray->size++;
        if (*str)
            str++;
    }
    warray->array[warray->size] = NULL;
    return warray;
}
