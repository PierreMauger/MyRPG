/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "game.h"

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
