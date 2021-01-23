/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
        dest[len + i + 1] = '\0';
    }
    return dest;
}