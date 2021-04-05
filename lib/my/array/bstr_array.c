/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "barray.h"

static int bcount_line(char const *file, char separator)
{
    int result = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i] == separator) {
            result++;
        }
        for (; file[i] == separator && file[i]; i++);
    }
    return result;
}

char **bstr_array(char const *file, char separator)
{
    char **map = NULL;
    int adv = 0;
    int x = 0;
    int y = 0;

    if (!file)
        return NULL;
    x = bcount_line(file, separator) + 1;
    map = bcalloc(sizeof(char *), x + 2);
    if (!map)
        return NULL;
    for (int nb_arr = 0; nb_arr < x; nb_arr++) {
        for (y = 0; file[adv + y] != separator && file[adv + y]; y++);
        map[nb_arr] = bstrndup(file + adv, y);
        for (; file[adv + y] == separator && file[adv + y]; y++);
        adv += y;
    }
    map[x + 1] = bstrndup(file + adv, y);
    return map;
}
