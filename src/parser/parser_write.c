/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

char *parser_write(char *buffer, char *name, char *new_name, int id)
{
    char *head = buffer;

    buffer = get_id(buffer, id);
    if (!buffer)
        return head;
    for (; bstrcmp(buffer, name); buffer++);
    buffer += bstrlen(name) + 3;
    for (int i = 0; new_name[i]; i++, buffer++) {
        *buffer = new_name[i];
    }
    return head;
}
