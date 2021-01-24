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
    game->pause = 0;
    game->turn = 0;
    game->p_mons = NULL;
    game->e_mons = NULL;
    init_mons(game);
    init_turn_ind(game);
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

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    destroy_mons(game->p_mons);
    destroy_mons(game->e_mons);
    destroy_turn_ind(game->ind);
    free(game);
}
