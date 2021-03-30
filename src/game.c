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

    window = sfRenderWindow_create(video_mode, "Raccon RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

void fight_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(GET_WINDOW)) {
        event_loop(game);
        if (game->set->pause == false) {
            update_all(game);
            draw_all(game);
        }
    }
}
