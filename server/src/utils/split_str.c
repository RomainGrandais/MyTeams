/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myftp-hugues.lejeune
** File description:
** split_str
*/

#include "utils.h"

static size_t get_substr_length(const char *str, const size_t len,
    const size_t word_pos, const char sep)
{
    size_t sep_count = 0;
    size_t str_len = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] == sep) {
            sep_count++;
            continue;
        }
        if (sep_count > word_pos)
            break;
        if (sep_count == word_pos)
            str_len++;
    }
    return str_len;
}

static char *fill_str(const char *str, const size_t word_pos,
    const size_t sub_len, const char sep)
{
    char *new = malloc(sizeof(char) * (sub_len + 1));
    size_t sep_count = 0;
    size_t count = 0;

    new[sub_len] = NULL_BYTE;
    if (new == NULL)
        return NULL;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == sep) {
            sep_count++;
            continue;
        }
        if (sep_count > word_pos)
            break;
        if (sep_count == word_pos && count < sub_len) {
            new[count] = str[i];
            count++;
        }
    }
    return new;
}

warray_t *split_str(warray_t *word_array, const char *str, char separator)
{
    size_t len;
    size_t sub_len;

    word_array->size = 1;
    if (str == NULL)
        return NULL;
    len = strlen(str);
    for (size_t i = 0; i < len; i++)
        if (str[i] == separator)
            word_array->size++;
    word_array->array = malloc(sizeof(char *) * (word_array->size + 1));
    if (word_array->array == NULL)
        return NULL;
    word_array->array[word_array->size] = NULL;
    for (size_t i = 0; i < word_array->size; i++) {
        sub_len = get_substr_length(str, len, i, separator);
        word_array->array[i] = fill_str(str, i, sub_len, separator);
    }
    return word_array;
}
