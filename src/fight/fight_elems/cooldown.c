/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void cooldown_refresh(mons_t *target)
{
    skill_t *temp = target->skill;

    while (temp != NULL) {
        temp->stat->act_cd = 0;
        temp = temp->next;
    }
}

void cooldown_reduce(game_t *game)
{
    skill_t *temp = game->ind->ptr_mons->skill;

    while (temp != NULL) {
        temp->stat->act_cd -= 1;
        if (temp->stat->act_cd < 0)
            temp->stat->act_cd = 0;
        temp = temp->next;
    }
}
