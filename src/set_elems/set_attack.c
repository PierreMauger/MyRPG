/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void target_team(game_t *game)
{
    if (game->turn == game->ind->ptr_skill->target[CURR_ATT])
        game->ind->team = game->e_mons;
    else
        game->ind->team = game->p_mons;
}

void set_attack(game_t *game)
{
    mons_t *temp;

    target_team(game);
    temp = game->ind->team;
    while (temp != NULL) {
        if (check_collide(game, temp) == 1) {
            atb_reset(game);
            game->ind->target = temp;
            if (game->ind->ptr_skill->aoe[CURR_ATT] == 1)
                aoe_hit(game);
            else
                set_attack_anim(game);
            game->ind->ptr_skill->act_cd = game->ind->ptr_skill->ini_cd;
        }
        if (temp != NULL)
            temp = temp->next;
    }
}
