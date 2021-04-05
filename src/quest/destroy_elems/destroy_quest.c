/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_quest(quest_t *quest)
{
    bfree_array(quest->start);
    bfree_array(quest->end);
    free(quest);
}
