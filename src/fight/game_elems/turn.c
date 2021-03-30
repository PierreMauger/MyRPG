/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void turn_loop(game_t *game)
{
    if (check_atb(game) == true) {
        game->ind->ptr_mons = get_higher_atb(game);
        if (game->set->attack == false) {
            game->ind->target = NULL;
            CURR_ATT = 0;
            cooldown_reduce(game);
            game->ind->ptr_skill = game->ind->ptr_mons->skill;
        }
        game->set->attack = true;
    }
    else {
        atb_increase(game->e_mons);
        atb_increase(game->p_mons);
    }
}
