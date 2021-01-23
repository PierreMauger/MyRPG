/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_strdup
*/

#include "my.h"

char *my_strndup(char const *src, int n)
{
    char *temp = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (; src[i] && i < n; i++)
        temp[i] = src[i];
    temp[i] = '\0';
    return (temp);
}
