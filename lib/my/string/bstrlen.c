/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "bstring.h"

size_t bstrlen(char const *str)
{
    size_t size_tab = 0;

    for (; str[size_tab]; size_tab++);
    return size_tab;
}
