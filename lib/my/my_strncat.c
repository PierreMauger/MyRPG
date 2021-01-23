/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int m = my_strlen(dest);

    for (int i = 0; i != nb; i++) {
        dest[m + i] = src[i];
        dest[m + i + 1] = '\0';
    }
    return (dest);
}
