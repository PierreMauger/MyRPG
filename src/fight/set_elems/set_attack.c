/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void target_team(game_t *game)
{
    if (game->set->turn == game->ind->ptr_skill->stat->target[CURR_ATT])
        game->ind->team = game->e_mons;
    else
        game->ind->team = game->p_mons;
}

void set_attack(game_t *game)
{
    target_team(game);
    for (mons_t *temp = game->ind->team; temp; temp = temp->next) {
        if (check_collide(game, temp) == 1) {
            atb_reset(game);
            game->ind->target = temp;
            if (game->ind->ptr_skill->stat->aoe[CURR_ATT] == 1)
                aoe_hit(game);
            else
                set_attack_anim(game);
            game->ind->ptr_skill->stat->act_cd =
            game->ind->ptr_skill->stat->ini_cd;
        }
    }
}

void set_auto_attack(game_t *game)
{
    target_team(game);
    atb_reset(game);
    game->ind->target = game->p_mons;
    if (game->ind->ptr_skill->stat->aoe[CURR_ATT] == 1)
        aoe_hit(game);
    else
        set_attack_anim(game);
    game->ind->ptr_skill->stat->act_cd =
    game->ind->ptr_skill->stat->ini_cd;
}
