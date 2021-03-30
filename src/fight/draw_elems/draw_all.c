/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_all(game_t *game)
{
    sfRenderWindow_clear(GET_WINDOW, sfBlack);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    if (game->set->in_anim == false && game->set->attack == true) {
        draw_turn_ind(game);
        draw_skill(game);
    }
    draw_attak_target(game);
    sfRenderWindow_display(GET_WINDOW);
}
