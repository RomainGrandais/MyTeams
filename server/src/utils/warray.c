/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-hugo.murat [WSL: Ubuntu]
** File description:
** warray
*/

#include "utils.h"

void free_warray(warray_t *warray)
{
    if (warray == NULL)
        return;
    if (warray->array != NULL) {
        for (size_t i = 0; i < warray->size; i++)
            free(warray->array[i]);
        free(warray->array);
    }
    free(warray);
}
