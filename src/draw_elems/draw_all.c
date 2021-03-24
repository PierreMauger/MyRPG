/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void draw_all(game_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    draw_mons(game, game->p_mons);
    draw_mons(game, game->e_mons);
    draw_turn_ind(game);
    if (game->set->in_anim == false && game->set->attack == true)
        draw_skill(game);
    draw_attak_target(game);
    sfRenderWindow_display(game->window->window);
}
