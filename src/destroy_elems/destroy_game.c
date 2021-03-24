/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    sfClock_destroy(game->time->clock);
    destroy_mons(game->p_mons);
    destroy_mons(game->e_mons);
    destroy_turn_ind(game->ind);
    free(game);
}
