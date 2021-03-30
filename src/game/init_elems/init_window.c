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
    game->window->w_size = (sfVector2f){1920, 1080};
    GET_WINDOW = create_window(game->window->w_size.x,
    game->window->w_size.y);
}
