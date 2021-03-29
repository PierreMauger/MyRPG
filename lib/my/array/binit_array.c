/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "barray.h"

char **binit_array(size_t x, size_t y)
{
    char **array = malloc(sizeof(char *) * (x + 1));

    if (!array)
        return NULL;
    bmemset(array, 0, x + 1);
    for (size_t i = 0; i < x; i++) {
        array[i] = malloc(sizeof(char) * (y + 1));
        if (!array[i])
            return NULL;
        bmemset(array[i], '\0', y + 1);
    }
    array[x] = NULL;
    return array;
}

char **binit_array_light(size_t x)
{
    char **array = malloc(sizeof(char *) * (x + 1));

    if (!array)
        return NULL;
    bmemset(array, 0, x + 1);
    array[x] = NULL;
    return array;
}
