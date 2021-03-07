/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "game",
    sfVideoMode_isValid(video_mode) ? sfDefaultStyle : sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        switch (game->state) {
            case MENU:
                game_loop(game);
                break;
            case PLAY:
                break;
            case GAME_OVER:
                break;
            case VICTORY:
                break;
        }
}
