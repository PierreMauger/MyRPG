/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

int *batoi_arr(char *src)
{
    int len = 1;
    int *arr = NULL;

    for (int i = 0; src[i]; i++)
        if (src[i] == ',')
            len++;
    arr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        arr[i] = batoi(src);
        for (; *src != ' ' && *src; src++);
        src++;
    }
    return arr;
}

char *get_id(char *buffer, int id)
{
    while (batoi(buffer) != id) {
        for (; bstrcmp(buffer, "\"id\"") && *buffer; buffer++);
        if (!*buffer)
            return NULL;
        buffer += 6;
    }
    return buffer;
}

size_t parser(char *buffer, char *str, int id)
{
    int i = 0;

    buffer = get_id(buffer, id);
    if (!buffer)
        return (size_t)NULL;
    for (; bstrcmp(buffer, str); buffer++);
    buffer += bstrlen(str) + 3;
    if (*buffer == '[') {
        buffer++;
        for (; buffer[i] != ']'; i++);
        return (size_t)batoi_arr(bstrndup(buffer, i));
    }
    if (*buffer == '"') {
        buffer++;
        for (; buffer[i] != '"'; i++);
        return (size_t)bstrndup(buffer, i);
    }
    else
        return (size_t)batoi(buffer);
}
