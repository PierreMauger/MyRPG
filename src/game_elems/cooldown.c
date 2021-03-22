/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void cooldown_reduce(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;

    while (temp != NULL) {
        temp->act_cd -= 1;
        if (temp->act_cd < 0)
            temp->act_cd = 0;
        temp = temp->next;
    }
}
