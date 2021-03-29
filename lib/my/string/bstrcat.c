/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "bstring.h"

char *bstrcat(char *dest, char const *src)
{
    int i = (int)bstrlen(dest);
    int j = 0;

    if (!dest || !src)
        return NULL;
    for (; src[j]; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
