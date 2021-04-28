/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

sfRenderWindow *create_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, 32};

    window = sfRenderWindow_create(
        video_mode, "Raccoon RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

void init_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->w_size = (sfVector2f){1920, 1080};
    GET_WINDOW = create_window(game->window->w_size.x,
    game->window->w_size.y);
    game->window->buffer = sfRenderTexture_create(game->window->w_size.x,
    game->window->w_size.y, sfFalse);
    game->window->tex = NULL;
    game->window->sprite = sfSprite_create();
}
