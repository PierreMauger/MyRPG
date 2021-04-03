/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void status_reduce_att(game_t *game)
{
    game->ind->ptr_mons->status->att_p -= 1;
    if (game->ind->ptr_mons->status->att_p < 0)
        game->ind->ptr_mons->status->att_p = 0;
    game->ind->ptr_mons->status->att_m -= 1;
    if (game->ind->ptr_mons->status->att_m < 0)
        game->ind->ptr_mons->status->att_m = 0;
}

void status_reduce_def(game_t *game)
{
    game->ind->ptr_mons->status->def_p -= 1;
    if (game->ind->ptr_mons->status->def_p < 0)
        game->ind->ptr_mons->status->def_p = 0;
    game->ind->ptr_mons->status->def_m -= 1;
    if (game->ind->ptr_mons->status->def_m < 0)
        game->ind->ptr_mons->status->def_m = 0;
}

void status_reduce_spe(game_t *game)
{
    game->ind->ptr_mons->status->spe_p -= 1;
    if (game->ind->ptr_mons->status->spe_p < 0)
        game->ind->ptr_mons->status->spe_p = 0;
    game->ind->ptr_mons->status->spe_m -= 1;
    if (game->ind->ptr_mons->status->spe_m < 0)
        game->ind->ptr_mons->status->spe_m = 0;
}

void status_reduce(game_t *game)
{
    if (game->ind->target == NULL || game->ind->ptr_mons == NULL)
        return;
    if (game->set->in_anim == false && check_atb(game) == true) {
        status_reduce_att(game);
        status_reduce_def(game);
        status_reduce_spe(game);
    }
}
