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
    return window;
}

void init_game(game_t *game)
{
    game->w_size = (sfVideoMode){1920, 1080, 32};
    game->window = create_my_window(game->w_size.width, game->w_size.height);
    game->clock = sfClock_create();
    game->state = 0;
}

void game_loop(game_t *game)
{

}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        switch (game->state) {
            case MENU:
                my_printf("case1, %d\n", game->state);
                break;
            case PLAY:
                my_printf("case2, %d\n", game->state);
                break;
            case GAME_OVER:
                my_printf("case3, %d\n", game->state);
                break;
            case VICTORY:
                my_printf("case4, %d\n", game->state);
                break;
        }
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    free(game);
}