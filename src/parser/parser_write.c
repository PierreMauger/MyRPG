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
    char *temp = malloc(bstrlen(buffer) + bstrlen(new_name) + 1);

    buffer = get_id(buffer, id);
    if (!buffer)
        return head;
    for (; bstrcmp(buffer, name); buffer++);
    buffer += bstrlen(name) + 3;
    bstrncpy(temp, head, bstrlen(head) - bstrlen(buffer));
    temp[bstrlen(head) - bstrlen(buffer)] = '\0';
    bstrcat(temp, new_name);
    for (; *buffer != '\n' && *buffer != ','; buffer++);
    bstrcat(temp, buffer);
    free(head);
    return temp;
}
