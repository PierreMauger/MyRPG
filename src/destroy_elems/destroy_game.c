/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_game(game_t *game)
{
    destroy_window(game->window);
    destroy_time(game->time);
    destroy_set(game->set);
    destroy_mons(game->p_mons);
    destroy_mons(game->e_mons);
    destroy_turn_ind(game->ind);
    sfFont_destroy(game->font);
    destroy_shader(game->shader);
    free(game);
}
