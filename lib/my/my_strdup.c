/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *temp = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i]; i++)
        temp[i] = src[i];
    temp[i] = '\0';
    return (temp);
}
