/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

void init_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->w_size = (sfVideoMode){1920, 1080, 32};
    game->window->window = create_my_window(game->window->w_size.width, game->window->w_size.height);
}
