/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void multi_hit(game_t *game, mons_t *target)
{
    if (target == NULL || game->ind->ptr_skill == NULL)
        return;
    if (game->ind->curr_attack < game->ind->ptr_skill->nbr_hit - 1) {
        set_anim_pos(game, game->ind->target);
        game->in_anim = true;
        game->ind->curr_attack += 1;
    }
}
