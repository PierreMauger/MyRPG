/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "bstring.h"

char *bstrndup(char const *src, size_t n)
{
    char *cp_src = malloc(sizeof(char) * (n + 1));
    size_t i = 0;
    size_t delay = 0;

    if (!cp_src)
        return NULL;
    for (; src[i] && i < n; i++)
        if (src[i] == '\\' && src[i + 1] == 'n') {
            cp_src[i] = '\n';
            delay++;
        }
        else
            cp_src[i] = src[i + delay];
    cp_src[i] = '\0';
    return cp_src;
}
