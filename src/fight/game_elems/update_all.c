/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void update_all(game_t *game)
{
    anim_all(game);
    if (game->set->in_anim == false)
        multi_hit(game, game->ind->target);
    if (game->set->in_anim == false)
        if (check_passive(game) == true)
            passive_action(game, game->ind->target);
    if (game->set->in_anim == false) {
        check_kill(game);
        turn_loop(game);
    }
}
