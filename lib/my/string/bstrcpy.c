/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "bstring.h"

char *bstrcpy(char *dest, char const *src)
{
    int adv = 0;

    if (!dest || !src)
        return NULL;
    for (; src[adv]; adv++)
        dest[adv] = src[adv];
    dest[adv] = '\0';
    return dest;
}
