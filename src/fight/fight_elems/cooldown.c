/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void cooldown_refresh(mons_t *target)
{
    for (skill_t *temp = target->skill; temp; temp = temp->next) {
        temp->stat->act_cd = 0;
    }
}

void cooldown_reduce(game_t *game)
{
    for (skill_t *temp = game->ind->ptr_mons->skill; temp; temp = temp->next) {
        temp->stat->act_cd -= 1;
        if (temp->stat->act_cd < 0)
            temp->stat->act_cd = 0;
    }
}
