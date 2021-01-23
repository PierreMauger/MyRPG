/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char c;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        j--;
    }
    return str;
}
