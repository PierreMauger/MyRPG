/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void check_multi_hit(game_t *game)
{
    if (game->set->in_anim == false)
        multi_hit(game, game->ind->target);
}

void check_passive(game_t *game)
{
    if (has_passive(game) == true && game->set->in_anim == false)
        passive_action(game, game->ind->target);
}

void check_turn(game_t *game)
{
    if (game->set->in_anim == false) {
        check_kill(game);
        turn_loop(game);
    }
}

void update_fight(game_t *game)
{
    if (game->ind->ptr_mons && game->ind->ptr_mons != game->p_mons &&
    game->set->attack && !game->set->in_anim)
        set_auto_attack(game);
    anim_all(game);
    check_multi_hit(game);
    check_passive(game);
    status_reduce(game);
    check_turn(game);
}
