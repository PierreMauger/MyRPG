/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void check_end(game_t *game)
{
    if (game->e_mons == NULL || game->p_mons == NULL)
        game->in_fight = 0;
}
//victory or lose

void fight_loop(game_t *game)
{
    while (game->in_fight) {
        event_fight_loop(game);
        if (game->set->pause == false) {
            update_fight(game);
            draw_fight(game);
            check_end(game);
        }
    }
}
