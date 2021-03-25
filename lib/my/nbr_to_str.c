/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strdup
*/

#include "my.h"

char *nbr_to_str(int nbr)
{
    int i = nbr;
    int j;
    char *res = malloc(5);
    res[0] = '0';
    res[1] = '\0';

    for (int c = 0; i != 0; c++) {
        j = i % 10;
        i = i / 10;
        res[c] = j + '0';
        res[c + 1] = '\0';
    }
    return my_revstr(res);
}
